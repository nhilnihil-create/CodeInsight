#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    map<int, int>m;
    m[0]++;
    int D[N + 1]; rep(i, N) cin >> D[i + 1], m[D[i + 1]]++;
    D[0] = 0;
    vector<int> f, f_bit;
    for(auto itr = m.begin(); itr != m.end(); ++itr) {
        if(itr -> second > 2) {
            cout << 0 << endl;
            return 0;
        }else if(itr -> second == 2) {
            f.pb(24 - itr -> first);
            f.pb(itr -> first);
        }else {
            if(itr -> first != 0 && itr -> first != 12) f_bit.pb(itr -> first);
        }
    }
    if(m[0] == 2 || m[12] == 2) {
        cout << 0 << endl;
        return 0;
    }
    f.pb(0);
    if(m[12] == 1) f.pb(12);
    int M = f_bit.size();
    int ans = 0;
    for(int bit = 0; bit < (1 << M); ++bit) {
        int minv = 100;
        vector<int> tmp = f;
        for(int i = 0; i < M; ++i) {
            if(bit & (1 << i)) {
                tmp.pb(24 - f_bit[i]);
            }else {
                tmp.pb(f_bit[i]);
            }
        }
        for(int i = 0; i < tmp.size(); ++i) {
            for(int j = i + 1; j < tmp.size(); ++j) {
                minv = min(minv, min(abs(tmp[j] - tmp[i]), 24 - abs(tmp[j] - tmp[i])));
            }
        }
        ans = max(minv, ans);
    }
    cout << ans << endl;
}
