#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    ll n = s.size();
    ll w = 0;
    for (ll i = 0; i < n; i++){
        if (s[i] == 'W'){
            w++;
        }
    }
    ll ans = 0;
    ll c = 0;
    for (ll i = 0; i < n; i++){
        if (s[i] == 'W'){
            ans += (i-c);
            c++;
        }
    }

cout << ans << endl;
}