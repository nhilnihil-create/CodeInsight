#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
    int n;cin >> n;
    vector<pair<ll,P>> table;
    rep(i,n){
        ll a,b;cin >> a >> b;
        P p = make_pair(a,b);
        pair<ll,P> q = make_pair(ll(a)+ll(b),p);
        table.push_back(q);
    }
    sort(table.rbegin(),table.rend());
    ll ans = 0;
    rep(i,n){
        P p = table[i].second;
        if(i%2==0) ans += p.first;
        else ans -= p.second;
    }
    cout << ans << endl;
}