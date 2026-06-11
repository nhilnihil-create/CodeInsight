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

const ll mod=998244353;

int main(){
    ll h,w,d;
    cin >> h >> w >> d;
    vector<vector<ll>> a(h,vector<ll>(w));
    vector<vector<pair<ll,pll>>> v(d);
    vector<vector<ll>> sum(d);
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
            pll s=make_pair(i,j);
            v[a[i][j]%d].push_back(make_pair(a[i][j],s));
        }
    }
    rep(i,d){
        sort(v[i].begin(),v[i].end());
        rep(j,v[i].size()){
            if(j==0){
                sum[i].push_back(0LL);
            }
            if(j){
                sum[i].push_back(sum[i][j-1]+abs(v[i][j].se.fi-v[i][j-1].se.fi)+abs(v[i][j].se.se-v[i][j-1].se.se));
            }
        }
    }
    ll q;
    cin >> q;
    rep(i,q){
        ll le,ri;
        cin >> le >> ri;
        ll p=(le-1)/d;
        ll q=le%d;
        ll r=(ri-1)/d;
        cout << sum[q][r]-sum[q][p] << endl;
    }
} 