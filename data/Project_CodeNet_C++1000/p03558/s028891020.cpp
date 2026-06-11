#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>


using namespace std;

typedef long long ll;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
typedef pair<int, int> pii;


int main() {
	int k;
	cin >> k;
	
	vector<vector<pii>> g(k);
	for (int i = 1; i < k;i++) {
		g[i].emplace_back(make_pair((i + 1) % k,1));
		g[i].emplace_back(make_pair((i * 10) % k,0));
	}

	vector<int> d(k,10*k);
	vector<int> isChecked(k);
	d[1] = 0;
	deque<int> deq;
	deq.push_front(1);
	while (!deq.empty()) {
		int v = deq.front();
		deq.pop_front();
		if (v == 0) {
			break;
		}
		if (!isChecked[v]) {

			for (int i = 0; i < g[v].size();i++) {

				if (g[v][i].second == 0) {
					d[g[v][i].first] = min(d[v], d[g[v][i].first]);
					deq.push_front(g[v][i].first);

				}
				else {
					d[g[v][i].first] = min(d[v]+1, d[g[v][i].first]);
					deq.push_back(g[v][i].first);
				}

			}

			isChecked[v] = true;
		}

	}
	cout << d[0] + 1 << endl;
}
