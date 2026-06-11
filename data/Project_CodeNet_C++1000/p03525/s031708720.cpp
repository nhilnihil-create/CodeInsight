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
typedef tuple<int, int, int> ti3;

const ll MOD_CONST = 1000000007;
//const ll MOD_CONST = 998244353;


const int INF = 1000000000;
//const ll INF = 1000000000000000000;


const int DAY_TIME = 24;

int main() {
	int n;
	cin >> n;
	int num = n + 1;
	vector<int> d(num);

	for (int i = 1; i < num; i++) {
		cin >> d[i];
		
	}

	map<int, int> m;
	for (int i = 0; i < num; i++) {
		m[d[i]]++;
	}

	vector<bool> isFilled(DAY_TIME);


	set<int> se;
	for (auto it = m.begin(); it != m.end(); it++) {
		int cnt = it->second;
		if (cnt > 2) {
			cout << 0 << endl;
			return 0;
		}


		int t = it->first;
		if (cnt == 2) {
			if (t == 0 || t == 12) {
				cout << 0 << endl;
				return 0;
			}

			isFilled[t] = true;
			isFilled[DAY_TIME - t] = true;
		}
		else {
			if (t == 0 || t == 12) {
				isFilled[t] = true;

			}
			else {
				se.insert(t);
			}
		}



	}

	int ans = 0;
	for (int b = 0; b < (1 << se.size()); b++) {
		vector<bool> isF(isFilled);
		int cnt = 0;
		for (auto it = se.begin(); it != se.end(); it++) {
			
			if ((b >> cnt) & 1) {
				isF[*it] = true;
				//cout << "right" << " ";
			}
			else {
				isF[DAY_TIME - *it] = true;
				//cout << "left" << " ";
			}
			cnt++;
			
		}
		//cout << endl;

		int s = INF;
		for (int i = 0; i < DAY_TIME; i++) {
			for (int j = i+1; j < DAY_TIME; j++) {
				if (isF[i] && isF[j]) {

					s = min(s,min(j - i, DAY_TIME + i - j));


				}
			}

		}

		//cout << s << " " << b<< endl;
		ans = max(ans, s);
	}

	

	cout << ans << endl;
}

