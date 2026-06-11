#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stdio.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(int i = (a); i < (int)(b); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vint;
typedef vector<string> vstr;
typedef pair<ll, ll> pint;
unsigned long long inf = (1LL << 62);
ll MOD = (ll)pow(10.0, 9.0) + 7;
pint dx[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

ll min(ll a, ll b)
{

	return (a < b) ? a : b;
}
ll max(ll a, ll b) { return (a > b) ? a : b; }


ll N;
int main() {
	cin >> N;
	

	vector<string> S(N);
	rep(i, N)
		cin >> S[i];


	ll ans = 0;
	for (int d = 0; d < N; d++) {

		if (d != 0) {
			string u = S[0];
			S.erase(S.begin());
			S.push_back(u);
			

		}


		bool flag = true;
		rep(i, N) {
			rep(j, N) {
				if (S[i][j] != S[j][i]) { flag = false;  break; }


			}
		}


		if (flag == true) {

			ans += N;
		}

	}

	cout << ans << endl;
	return 0;
}