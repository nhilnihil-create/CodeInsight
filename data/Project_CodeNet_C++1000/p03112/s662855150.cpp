#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int a, b; cin >> a >> b;
    int q; cin >> q; 
    vector<ll> s(a), t(b);
    for(int i = 0; i < a; i++){
        cin >> s.at(i);
    }
    for(int i = 0; i < b; i++){
        cin >> t.at(i);
    }
    for(int i = 0; i < q; i++){
        int sh, ch;
        ll dist; cin >> dist;
        sh = lower_bound(s.begin(), s.end(), dist) - s.begin();
        ch = lower_bound(t.begin(), t.end(), dist) - t.begin();
        ll ans = 1001001001001;
        for(int j = 0; j <= 1; j++){
            for(int k = 0; k <= 1; k++){
                int sht = sh - j;
                int cht = ch - k;
                if(sht < 0 || cht < 0 || sht >= a || cht >= b) continue;
                ans = min(ans, abs(dist - s.at(sht)) + abs(s.at(sht) - t.at(cht)));
                ans = min(ans, abs(dist - t.at(cht)) + abs(s.at(sht) - t.at(cht)));
            }
        }
        cout << ans << endl;
    }
}
