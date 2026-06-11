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

const ll INF=1e18;

int main()
{
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pll> a;
    ll cnt=0;
    rep(i,n){
        if(i==0){
            cnt++;
            continue;
        }
        if(s[i]==s[i-1]){
            cnt++;
        }
        else{
            a.push_back(make_pair((ll)(s[i-1]-'0'),cnt));
            cnt=1;
        }
    }
    a.push_back(make_pair((ll)(s[n-1]-'0'),cnt));
    ll m=a.size();
    vector<ll> sum(m+1);
    rep(i,m){
        sum[i+1]=sum[i]+a[i].se;
    }
    ll ans=0;
    rep(i,m){
        if(a[i].fi==1){
            ans=max(ans,sum[min(m,i+2*k+1)]-sum[i]);
        }
        else{
            ans=max(ans,sum[min(m,i+2*k)]-sum[i]);
        }
    }
    cout << ans << endl;
    return 0;
} 