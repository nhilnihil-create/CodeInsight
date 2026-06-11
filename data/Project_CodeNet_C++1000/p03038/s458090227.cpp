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

const ll mod=1e9+7;

int main()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<pll> b(m);
    rep(i,m){
        cin >> b[i].se >> b[i].fi;
    }
    sort(b.rbegin(),b.rend());
    ll num=0;
    ll sum=0;
    rep(i,n){
        if(a[i]>=b[num].fi){
            sum+=a[i];
        }
        else{
            b[num].se--;
            sum+=b[num].fi;
        }
        if(b[num].se==0 && num<m-1){
            num++;
        }
        else if(b[num].se==0 && num==m-1){
            for(ll j=i+1;j<n;j++){
                sum+=a[j];
            }
            break;
        }
    }
    cout << sum << endl;
    return 0;
} 