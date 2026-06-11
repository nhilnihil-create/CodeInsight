#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<fstream>
#include<time.h>
#include<iterator>
#include<random>

//#pragma warning( disable:4996 )
using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()

int MOD = (ll)1000000000 + 7;

const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;
const int MAX = 500050;


int N, D[100];
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	REP(i, N) {
		cin >> D[i];
		D[i] = min(D[i], 24 - D[i]);
	}
	int ans = 0;
	if (N >= 24) {
		print(0);
		return 0;
	}
	else if (N >= 12) {
		map<int, int>mp;
		mp[0] = 1;
		REP(i, N) {
			mp[D[i]]++;
		}
		ans = 1;
		REP(i, 13) {
			if (mp[i] >= 3)ans = 0;
		}
		print(ans); return 0;
	}
	else {
		FOR(i,0, 1 << N) {
			multiset<int>st;
			st.insert(0);
			REP(j, N) {
				if (i&(1<< j)) {
					st.insert(24 - D[j]);
					//pe(24 - D[j]);
				}
				else {
					st.insert(D[j]);
					//pe(D[j]);
				}
			}
			//cout << endl;
			auto itr1 = st.begin(), itr2 = st.begin();
			itr2++;
			int res = INF;
			while (itr2 != st.end()) {
				int dif = 0;
				if (*itr1 == 0) {
					dif = min(*itr2, 24 - *itr2);
				}
				else if (*itr2 == 0) {
					dif = min(*itr1, 24 - *itr1);
				}
				else {
					dif = abs(*itr1 - *itr2);
				}
				res = min(res,dif);
				itr1++; itr2++;
			}
			res = min(res,min(*itr1, 24 - *itr1));
			ans = max(ans, res);
		}
	}
	print(ans);
}
