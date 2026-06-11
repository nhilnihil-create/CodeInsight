#include <bits/stdc++.h>
using namespace std;
using vi  = vector<int>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define pow2(i) (1<<i)
#define BIT(X,i) ((X>>i)&1)
#define DEBUG(x) cerr<<__LINE__<<": "<<#x<<" = "<<x<<"\n"
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
const int INF = 1e9;

int main() {
    string s; cin >> s;
    int N = s.length();

    vi albits(N+1, 0);
    rep(i,N) {
        int c = s[i] - 'a';
        albits[i+1] ^= pow2(c);
        albits[i+1] ^= albits[i];
    }
    vi dp((1<<26), INF);
    vi ans(N+1, INF);
    dp[albits[0]] = 0;
    ans[0] = 0;
    rep(i,N) {
        rep(j,27) {
            int x = pow2(j) / 2;
            chmin(ans[i+1], dp[albits[i+1]^x] + 1);
        }
        chmin(dp[albits[i+1]], ans[i+1]);
    }
    cout << ans[N] << endl;
    return 0;
}
