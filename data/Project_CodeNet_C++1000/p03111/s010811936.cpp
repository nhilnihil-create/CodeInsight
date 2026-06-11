//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b>> c;
    vi l(n);
    rep(i, n) {
        cin >> l[i];
    }

    ll ans = LINF;
    rep(i, 1<<(n<<1)) {
        vector<bool> ch(3);
        rep(j, n) {
            rep(k, 3) {
                if((i>>(j<<1))%4 == k+1) {
                    ch[k] = true;
                }
            }
        }
        bool ss = true;
        rep(j, 3) {
            if(!ch[j]) {
                ss = false;
            }
        }

        if(ss) {
            int now = 0;
            vvi gg(3);
            rep(j, n) {
                rep(k, 3) {
                    if((i>>(j<<1))%4 == k+1) {
                        gg[k].push_back(j);
                    }
                }
            }
            now += gg[0].size() + gg[1].size() + gg[2].size() - 3;
            now *= 10;
            vi si(3);
            rep(j, 3) {
                rep(k, gg[j].size()) {
                    si[j] += l[gg[j][k]];
                }
            }
            
            now += abs(si[0] - a);
            now += abs(si[1] - b);
            now += abs(si[2] - c);
            ans = min(ans, (ll)now);
            //cout << now << endl;
            //cout << bitset<8> (i) << endl;
        }
    }

    cout << ans << endl;
}