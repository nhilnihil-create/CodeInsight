//	Totally unrelated and not AT ALL stolen from hohohaha's, generic_placeholder_name's or katoriyuu's template
#include <bits/stdc++.h>

using namespace std;

// #pragma GCC optimize("O3")
// #pragma GCC target("avx")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define gcd __gcd
#define rep(i,s,end) for(int i = (s); i <  (end); ++i)
#define rep0(i, end) for(int i =   0; i <= (end); ++i)
#define rep1(i, end) for(int i =   1; i <= (end); ++i)
#define lb lower_bound
#define ub upper_bound

#define vt vector
#define endl "\n"

#define fileopen(filename, in_type, out_type) if (fopen(filename in_type, "r")) {freopen(filename in_type, "r", stdin);freopen(filename out_type, "w", stdout);}
#define local_input(x) if (x && fopen("input.txt","r")) freopen("input.txt","r",stdin);
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define fscan(x)   scanf("%d",  &x)
#define fscandb(x) scanf("%lf", &x)
#define fscanll(x) scanf("%lld",&x)
//	Until next time, remember:
//			You are closer than you think.
//						_Dan Lok_

#define db double
#define ll long long
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define pi 3.1415926535897932	//faster than pi = acos(-1); but sometimes doesn't work?
//	srand(chrono::steady_clock::now().time_since_epoch().count());
//	freopen("input.txt","r",stdin);

#define mn 1 << 18
int n;
int id1[mn],id2[mn],dp1[mn],dp2[mn];
signed main()
{
	cin >> n; rep(i,0,1 << n){
		cin >> dp1[i]; id1[i] = i, dp2[i] = id2[i] = -1;
	}
	rep(i,1,1 << n){
		rep(j,0,n) if(i & (1 << j)){
			int jj = i ^ (1 << j);
			if(jj){
				if(id1[i] == id1[jj]) continue;
				else if(dp1[i] <= dp1[jj]){
					dp2[i] = dp1[i],  id2[i] = id1[i];
					dp1[i] = dp1[jj], id1[i] = id1[jj];
					if(dp2[i] <= dp2[jj] && id2[i] != id2[jj]){
						dp2[i] = dp2[jj], id2[i] = id2[jj];
					}
				}
				else if(dp2[i] <= dp1[jj] && id2[i] != id1[jj]){
					dp2[i] = dp1[jj], id2[i] = id1[jj];
				}
			}
			else{
				if(dp1[0] > dp1[i]){
					dp2[i] = dp1[i], id2[i] = id1[i];
					dp1[i] = dp1[0], id1[i] = id1[0];
				}
				else if(dp1[0] > dp2[i]){
					dp2[i] = dp1[0], id2[i] = id1[0];
				}
			}
		}
	}
	int ans = 0;
	rep(i,1,1 << n){
		cout << (ans = max(ans, dp1[i] + dp2[i])) << endl;
	}
	return 0;
}
// with the aura of Dora, AC!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Why is there a one in my row of exclamation marks?
 