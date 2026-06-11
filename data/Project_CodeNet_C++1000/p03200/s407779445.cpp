#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    string s;
    cin >> s;
    ll blacks = 0;
    ll ans = 0;
    for (ll i = 0; i < s.length(); i++) {
        if (s[i] == 'B') {
            blacks++;
        } else {
            ans += blacks;
        }
    }
    cout << ans;
}
