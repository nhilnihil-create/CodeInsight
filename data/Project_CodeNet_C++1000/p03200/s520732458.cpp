#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    string s;
    cin >> s;

    ll ans = 0;
    ll j = 0;
    rep(i, s.size()){
        if(s[i] == 'W'){
            ans += i-j;
            j++;
        }
    }
    cout << ans << endl;

    return 0;
}
