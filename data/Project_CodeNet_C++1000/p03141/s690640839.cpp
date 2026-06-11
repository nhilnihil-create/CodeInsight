#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e9+7;

int main(){
    ll n;
    cin >> n ;
    vector<ll> a(n),b(n);
    vector<pll> ans(n);
    rep(i,n){
        cin >> a[i] >> b[i];
        ans.push_back({a[i]+b[i],i});
    }
    sort(ans.rbegin(),ans.rend());
    ll cnt=0;
    ll tot=0;
    while(cnt<n){
        if(cnt%2==0){
            tot+=a[ans[cnt].se];
        }
        else{
            tot-=b[ans[cnt].se];
        }
        cnt++;
    }
    cout << tot << endl;
}