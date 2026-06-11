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
    int n;
    cin >> n;
    int d[50];
    rep(i, n) {
        cin >> d[i];
    }

    int dd[24] = {};
    dd[0]++;
    rep(i, n) {
        if(dd[d[i]]) {
            dd[(24-d[i])%24]++;
        } else {
            dd[d[i]]++;
        }
    }
    bool x = true;
    vi ii;
    rep(i, 24) {
        if(dd[i] > 1) {
            cout << 0 << endl;
            return 0;
        }
        if(i && dd[i] && !dd[24-i]) {
            if(x) {
                ii.push_back(i);
            }
            x ^= 1;
        }
    }
    for(int xx:ii) {
        swap(dd[xx], dd[24-xx]);
    }
    int ans = INF;
    int now = -5000;
    int s;
    rep(i, 24) {
        if(dd[i]){
            if(now == -5000) {
                s = i;
            }
            ans = min(ans, abs(now-i));
            now = i;
            //cout << i << endl;
        }
    }
    ans = min(ans, abs(s-now+24));
    cout << ans << endl;
}