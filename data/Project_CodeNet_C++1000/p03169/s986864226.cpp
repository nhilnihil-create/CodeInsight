#pragma GCC optimize("O2")

#include <bits/stdc++.h>
#ifdef DEBUG
    #include "debug.hpp"
#endif

using namespace std;

#define all(c) (c).begin(), (c).end()
#define traverse(c, it) for(auto it = (c).begin(); it != (c).end(); it++)
#define rep(i, N) for(int i = 0; i < (N); i++)
#define rep1(i, N) for(int i = 1; i <= (N); i++)
#define rep2(i, s, e) for(int i = (s); i <= (e); i++)
#define rep3(i, s, e, d) for(int i = (s); (d) >= 0 ? i <= (e) : i >= (e); i += (d))
#define pb push_back


#ifdef DEBUG
    #define debug(x...) {dbg::depth++; string dbg_vals = dbg::to_string(x); dbg::depth--; dbg::fprint(__func__, __LINE__, #x, dbg_vals);}
    #define light_debug(x) {dbg::light = 1; dbg::dout << __func__ << ":" << __LINE__ << "  " << #x << " = " << x << endl; dbg::light = 0;}
#else
    #define debug(x...)
    #define light_debug(x) 
#endif

template<typename T>
T& ckmin(T& a, T b){ return a = a > b ? b : a; }

template<typename T>
T& ckmax(T& a, T b){ return a = a < b ? b : a; }

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int N;
long double dp[301][301][301];
bool ch[301][301][301];

long double rec(int one, int two, int three){
	int zero = N - one - two - three;
	if(zero == N) return 0;
	if(ch[one][two][three]) return dp[one][two][three];
	ch[one][two][three] = 1;
	long double p0 = (long double)zero / N;
	long double p1 = (long double)one / N;
	long double p2 = (long double)two / N;
	long double p3 = (long double)three / N;

	long double ans = 1;
	if(one) ans += p1 * rec(one - 1, two, three);
	if(two) ans += p2 * rec(one + 1, two - 1, three);
	if(three) ans += p3 * rec(one, two + 1, three - 1);
	ans *= (long double)1 / (1 - p0);
	return dp[one][two][three] = ans;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifdef DEBUG
        freopen("debug", "w", stderr);
    #endif

   	cin >> N;
   	int cnt[4];
   	memset(cnt, 0, sizeof cnt);
   	rep(i, N){
   		int a;
   		cin >> a;
   		cnt[a]++;
   	}
    
   	cout << fixed << setprecision(16) << rec(cnt[1], cnt[2], cnt[3]) << '\n';
    #ifdef DEBUG
        dbg::dout << "\nExecution time: " << clock() << "ms\n";
    #endif

    return 0;
}
