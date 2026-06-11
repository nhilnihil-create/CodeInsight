#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> s, t;
void solve(){
    int x;
    cin >> x;

    int ans = 1e18;
    int sitr = lower_bound(s.begin(),s.end(),x) - s.begin();
    int titr = lower_bound(t.begin(),t.end(),x) - t.begin();

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans = min(ans, abs(x - s[sitr - i]) + abs(t[titr - j] - s[sitr - i]));
            ans = min(ans, abs(x - t[titr - j]) + abs(t[titr - j] - s[sitr - i]));
        }
    }
    cout << ans << endl;
}

signed main(){
    int a,b,q;
    cin >> a >> b >> q;

    s.resize(a);
    t.resize(b);
    for (int i = 0; i < a; i++) cin >> s[i];
    for (int i = 0; i < b; i++) cin >> t[i];

    s.push_back(-1e18);
    t.push_back(-1e18);
    s.push_back(1e18);
    t.push_back(1e18);
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    while(q--){
        solve();
    }
}