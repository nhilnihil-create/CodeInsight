#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1<<29;
using Graph = vector<vector<int>>;
int main() {
    int D,G,p[11],c[11]; 
    cin >> D >> G;
    for (int i=0; i<D; ++i) cin >> p[i] >> c[i];

    int ans = 1e9;
    
    for (int mask = 0; mask < (1<<D); ++mask){
        int s = 0, num = 0, rest_max = -1;
        for (int i=0; i<D; ++i){
            if (mask & (1<<i)){
                s += 100 * (i+1) * p[i] + c[i];
                num += p[i];
            }else {
                rest_max = i;
            }
        }
        if (s < G){
            int s1 = 100 * (rest_max + 1);
            int need = (G - s + (s1 - 1)) / s1;
            if (need >= p[rest_max]) continue;
            num += need;
        }
        chmin(ans, num);
    }

    cout << ans << endl;
    return 0;
}