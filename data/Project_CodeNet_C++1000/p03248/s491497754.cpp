#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    string s;
    cin >> s;
    n = s.size();
    if(s[0]=='0' || s.back()=='1' || s[n-2]=='0'){
        cout << -1 << endl;
        return 0;
    }
    s[n-1] = '1';
    for(i=0;i*2<n-1;i++){
        if(s[i]!=s[n-2-i]){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<vector<ll>> G(n+1);
    ll now;
    ll root = n;
    for(i=n-2;i>=0;i--){
        G[root].push_back(i+1);
        if(s[i]=='1'){
            root = i+1;
        }
    }
    for(i=1;i<=n;i++){
        for(ll x:G[i]){
            cout << i << " " << x << endl;
        }
    }
    return 0;
}