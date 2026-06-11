#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;
ll const mod = 998244353;
const ll MAX = 300000;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvp = vector<vector<P>>;
int main() {
    int d, g;
    cin >> d >> g;
    vi p(d), c(d);
    rep(i, d) {
        cin >> p[i] >> c[i];
    }
    int db = 0;
    int ans = INF;
    rep(i, 1 << d) {
        int sum = 0, res = 0;
        if (i >= 24) {
            int k = 65;
        }
        rep(j, d) {
            if (i >> j & 1) {
                sum += (p[j] * 100 * (j + 1) + c[j]);
                res += p[j];
            }
        }
        if (sum >= g) {
            ans = min(ans, res);
            if (ans == res)db = i;
        }
        else {
            int get = 0;
            rep(j, d) {
                if (!(i >> j & 1)) {
                    get = j;
                }
            }
            int cnt = 0;
            while (g - sum > 0) {
                sum += ((get + 1) * 100);
                cnt++;
                if (cnt >= p[get])break;
            }
            if (sum >= g) {
                ans = min(ans, res + cnt);
                if (res + cnt == ans)db = res + cnt;
            }
        }
    }
   
    //cout << db << endl;
    cout << ans << endl;
    return 0;
}