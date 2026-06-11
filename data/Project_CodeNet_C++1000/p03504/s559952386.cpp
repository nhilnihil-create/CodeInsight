#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


ll s[100010], t[100010], c[35];

ll ch[35][100010];

int main(){
    int n, C;
    cin >> n >> C;
    rep(i, n){
        cin >> s[i] >> t[i] >> c[i];
        ch[c[i]][s[i]]++;
        ch[c[i]][t[i]]--;
    }
    rep(i, 35) rep(j, 100009){
        ch[i][j+1] += ch[i][j];
    }

    rep(i, 35) rep(j, 100009){
        if (ch[i][j] == 0 && ch[i][j+1] == 1) ch[i][j]++;
    }

    int ans = 0;
    rep(j, 100009) {
        int tmp = 0;
        rep(i, 35) tmp += ch[i][j];
        ans = max(ans, tmp);
    }


    cout << ans << endl;

    return 0;
}
