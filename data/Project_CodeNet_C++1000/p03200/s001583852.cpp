#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;

    ll cnt = 0, ans = 0;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == 'W') {
            cnt++;
            ans += i + 1 - cnt;
        }
    }

    cout << ans << endl;
    
}