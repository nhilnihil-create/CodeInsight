//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    ll n,m; cin>>n>>m;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    rep(i,n){
        ll a; cin>>a;
        pq.push(a);
    }

    vector<vector<ll>>bc(m,vector<ll>(2));
    rep(i,m)cin>>bc[i][1]>>bc[i][0];
    sort(bc.begin(),bc.end());
    reverse(bc.begin(),bc.end());
    rep(i,m){
        ll cnt=0;
        ll B=bc[i][0];
        while(B>pq.top()){
            pq.pop();
            pq.push(B);
            cnt++;
            if(cnt==bc[i][1])break;
        }
    }
    ll ans=0;
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans<<endl;
}

















































