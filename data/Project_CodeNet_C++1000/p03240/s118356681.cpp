#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cout << "[" << #var << "] " << var << endl
const ll mod = 1000000007;
const int INF = 1001001001;


int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> h(n);
    rep(i, n) cin >> x[i] >> y[i] >> h[i];
    int cx, cy;
    int hmax;
    bool ok;

    rep(i, 101) {
        rep(j, 101) {
            ok = true;
            cx = i;
            cy = j;
            hmax = 0;
            rep(k, n) {
                if (h[k]==0) continue;
                hmax = h[k] + abs(x[k]-cx) + abs(y[k]-cy);
                break;
            }
            if (hmax==0) {
                hmax = 1;
                break;
            }
            rep(k, n) {
                int ih = h[k] + abs(x[k]-cx) + abs(y[k]-cy);
                if (h[k]==0) {
                    if (ih<hmax) {
                        ok = false;
                        break;
                    }
                }
                else {
                    if (ih!=hmax) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) break;
        }
        if (ok) break;
    }
    
    
    
    
    cout << cx << " " << cy << " " << hmax << endl;
    return 0;
}
