#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n),b(m),c(m);
    rep(i,n) cin >> a[i];
    rep(i,m){
        cin >> b[i];
        cin >> c[i];
    }
    priority_queue<pair<int,int>> q;
    rep(i,n){
        q.push(make_pair(a[i],1));
    }
    rep(i,m){
        q.push(make_pair(c[i],b[i]));
    }
    ll ans=0;
    rep(i,n){
        auto p = q.top();
        q.pop();
        ans += p.first;
        if(p.second>1){
            p.second--;
            q.push(p);
        }
    }
    cout << ans << endl;
    
    
}