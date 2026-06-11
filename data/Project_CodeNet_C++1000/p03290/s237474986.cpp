//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int d, G;
    cin >> d >> G;
    vi p(d);
    vi c(d);
    vi sum(d);
    vi po(d);
    rep(i, d) {
        cin >> p[i] >> c[i];
        sum[i] = 100*(i+1)*p[i] + c[i];
        po[i] = 100*(i+1)*p[i];
    }

    int ans = INT_MAX;
    rep(i, 1<<d) {
        int now = 0;
        int num = 0;
        rep(j, d) {
            if((i >> j) & 1) {
                now += sum[j];
                num += p[j];
            }
        }
        now = G-now;
        if(now <= 0) {
            ans = min(ans, num);
            continue;
        }
        for(int j = d-1; j >= 0; --j) {
            if((i>>j)&1) continue;
            if(po[j] >= now) {
                ans = min(ans, num + (now+100*(j+1)-1)/(100*(j+1)));
                break;
            }
        }
    }

    cout << ans << endl;
}