#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    multimap <int, int> tc;
    int t, c;
    for (int i=0; i<N; i++) {
        cin >> c >> t;
        tc.insert(pair<int, int>(t,c));
    }
    int res=1000;
    bool ac = false;
    for (auto x : tc) {
        if (x.first<=T) {
            res=min(x.second, res);
            ac = true;
        }
    }
    if (ac) cout << res;
    else cout << "TLE";
}