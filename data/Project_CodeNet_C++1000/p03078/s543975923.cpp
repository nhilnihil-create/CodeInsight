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

const ll INF=3*10000000000;

int main()
{
    ll x,y,z,k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x),b(y),c(z);
    rep(i,x){
        cin >> a[i];
    }
    rep(i,y){
        cin >> b[i];
    }
    rep(i,z){
        cin >> c[i];
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    sort(c.rbegin(),c.rend());
    vector<ll> sum(x*y);
    rep(i,x){
        rep(j,y){
            sum[x*j+i]=a[i]+b[j];
        }
    }
    sort(sum.rbegin(),sum.rend());
    vector<ll> ans;
    rep(i,min(x*y,3000LL)){
        rep(j,z){
            ans.push_back(sum[i]+c[j]);
        }
    }
    sort(ans.rbegin(),ans.rend());
    rep(i,k){
        cout << ans[i] << endl;
    }
    
    return 0;
} 