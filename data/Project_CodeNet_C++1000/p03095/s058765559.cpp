#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
int main(){
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> a(26);
    ll i,j;
    for(i=0;i<n;i++){
        a.at((int)(s.at(i)-'a'))++;
    }
    ll ans = 1;
    for(i=0;i<26;i++){
        ans=ans*(a.at(i)+1)%mod;
    }
    cout << ans-1 << endl;
    return 0;
}