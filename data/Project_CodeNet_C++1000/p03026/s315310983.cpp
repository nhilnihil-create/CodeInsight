#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
#include<iomanip>
#include<tuple>
#include<stack>

#define _USE_MATH_DEFINES
#include<math.h>


using namespace std;
typedef long long ll;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef tuple<int, int, int> ti3;

const ll MOD_CONST = 1000000007;
//const ll MOD_CONST = 998244353;


const int BIG_NUM = 1000000005;
const ll INF = 1000000000000000000;

//const vector<vector<int>> DIR{ {1,0},{0,1},{-1,0},{0,-1} };

//const double EPS = 1e-10;


int main() {
	int n;
	cin >> n;

	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	priority_queue<int> c;
	for (int i = 0; i < n; i++) {
		int ci;
		cin >> ci;
		c.push(ci);
	}

	vector<pii> deg(n);
	for (int i = 0; i < n; i++) {
		deg[i] = make_pair(g[i].size(), i);
	}

	

	vector<int> d(n);
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push(deg[0]);
	

	ll sum = 0;
	vector<bool> isChecked(n);
	
	while(!pq.empty()){
		int v = pq.top().second;
		pq.pop();
		d[v] = c.top();
		c.pop();
		for (int u : g[v]) {
			if (isChecked[u]) {

				sum += d[v];
				continue;
			}
			

			
			
			pq.push(deg[u]);
		}

		
		
		isChecked[v] = true;

	}

	std::cout << sum << endl;
	for (int di : d) {
		std::cout << di << " ";
 	}
}

