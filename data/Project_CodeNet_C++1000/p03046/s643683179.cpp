#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

const ll mod=1e9+7;


int main(){
    ll m,k;
    cin >> m >> k;
    if(k==0){
        rep(i,(1<<m)){
            rep(j,2){
                if(i || j) cout << " ";
                cout << i;
            }
        }
        cout << endl;
        return 0;
    }
    if(k<(1<<m) && !(k==1 && m==1)){
        vector<ll> ans;
        ans.push_back(0);
        ans.push_back(k);
        ans.push_back(0);
        for(ll i=1;i<(1<<m);i++){
            if(i==k) continue;
            ans.push_back(i);
        }
        ans.push_back(k);
        for(ll i=(1<<m)-1;i>=1;i--){
            if(i==k) continue;
            ans.push_back(i);
        }
        rep(i,(1<<m+1)){
            if(i) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
        return 0;
    }
    return 0;
}