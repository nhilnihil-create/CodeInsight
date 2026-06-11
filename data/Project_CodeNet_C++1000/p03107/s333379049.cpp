#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    ll n = s.size();
    ll z = 0, o = 0;

    for (ll i = 0; i < n; i++){
        if (s[i] == '0'){
            z++;
        }
        else{
            o++;
        }
    }

    cout << n - abs(z-o) << endl;
}