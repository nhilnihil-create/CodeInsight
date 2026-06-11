/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r)        for (int i = l; i < r; i++)
//#define ForE(i, l, r)       for (int i = l; i <= r; i++)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// geometry calculate
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9+7;
const int MAXN = 100005, MAXM = 200010;
// code
#define int long long

int a[1 << 20], N;
pii ans[1 << 20];

// get two largest number
void merge(int x, int y){
	if(ans[y].S >= ans[x].F){
		ans[x].F = ans[y].F;
		ans[x].S = ans[y].S;
	}else if(ans[y].S <= ans[x].F && ans[y].F >= ans[x].F){
		ans[x].S = ans[x].F;
		ans[x].F = ans[y].F;
	}else if(ans[y].F <= ans[x].F && ans[y].F >= ans[x].S){
		ans[x].S = ans[y].F;
	}
}

void Solve() {
    cin >> N;
    for (int i = 0; i < (1 << N); i ++){
        cin >> ans[i].F; ans[i].S = -1;
    }

    for (int d = 0; d < N; d++){
        for(int i = 0; i < (1 << N); i ++) if((i & (1 << d)) == 0){
            merge(i | (1 << d), i);
		}

    }

    int res = 0;
    for (int i = 1; i < (1 << N); i++){
        res = max(res, ans[i].F + ans[i].S);
        cout << res << endl;
    }
}

signed main(){
    open("", ".in", ".out");
    FAST_IO;
    int TC = 1;
    //cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\

+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/
