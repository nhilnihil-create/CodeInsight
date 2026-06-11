#include <bits/stdc++.h>

using namespace std;

using ll = long long;


ll arr[295785];

int main(){
    ll n; cin >> n;
    ll q; cin >> q;
    string s; cin >> s;
    for(ll i = 1; i < n; ++i){
        if(s[i] == 'C' && s[i - 1] == 'A')arr[i] = arr[i - 1] + 1;
        else arr[i] = arr[i - 1];
    }
    while(q--){
        ll l, r;
        cin >> l >> r;
        cout << arr[r - 1] - arr[l - 1] << endl;
    }
    return 0;

}
