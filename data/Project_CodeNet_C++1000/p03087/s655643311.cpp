#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,q;
    string s;
    cin >> n >> q >> s;
    vector<ll> l(q);
    vector<ll> r(q);
    for (ll i = 0;i < q;i++){
        cin >> l[i] >> r[i];
    }
    vector<ll> ac(n);
    int c = 0;
    ac[0] = 0;
    for (ll i = 0;i < n-1;i++){
        if (s[i] == 'A' && s[i+1] == 'C'){
            c++;
        }
        ac[i+1] = c;
    }
    /*for (ll i = 0; i < n; i++){
        cout << ac[i] << endl;
    }*/

    for (ll i = 0; i < q; i++){
        if (l[i] == 1){
            cout << ac[r[i]-1] << endl;
        }
        else if (s[l[i]-1] == 'C' && s[l[i]-2] == 'A'){
            cout << ac[r[i]-1] - ac[l[i]-2] -1 << endl;
        }
        else{
            cout << ac[r[i]-1] - ac[l[i]-2] << endl;
        }
    }
    
}