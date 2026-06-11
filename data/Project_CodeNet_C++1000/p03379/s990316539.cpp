#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> x(n);
    for (ll i = 0;i < n;i++){
        cin >> x[i];
    }
    vector<ll> s(n);
    for (ll i = 0;i < n;i++){
        s[i] = x[i];
    }
    sort(s.begin(), s.end());
    ll ms = s[(n/2)-1];
    ll ml = s[n/2];

    if (ms == ml){
        for (ll i = 0; i < n; i++){
            cout << ms << "\n";
        }
    }
    else{
        for (ll i = 0; i < n; i++){
            if (x[i] >= ml){
                cout << ms << "\n";
            }
            else{
                cout << ml << "\n";
            }
        }
    }
}