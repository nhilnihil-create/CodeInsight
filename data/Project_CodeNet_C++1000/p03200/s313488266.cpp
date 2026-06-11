#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
int black;
ll ans;

void solve() {
    cin >> s;
    black = 0, ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'B') black++;
        else ans += black;
    }
    cout << ans << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

}