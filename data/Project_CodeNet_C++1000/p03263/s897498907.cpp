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
    ll h,w;
    cin >> h >> w;
    vector<vector<ll>> a(h,vector<ll>(w));
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    vector<pll> be,af;
    rep(i,h-1){
        rep(j,w){
            if(a[i][j]%2==1){
                a[i][j]--;
                a[i+1][j]++;
                be.push_back(make_pair(i+1,j+1));
                af.push_back(make_pair(i+2,j+1));
            }
        }
    }
    rep(i,w-1){
        if(a[h-1][i]%2==1){
            a[h-1][i]--;
            a[h-1][i+1]++;
            be.push_back(make_pair(h,i+1));
            af.push_back(make_pair(h,i+2));
        }
    }
    cout << be.size() << endl;
    rep(i,be.size()){
        cout << be[i].fi << " " << be[i].se << " " << af[i].fi << " " << af[i].se << endl;
    }
    return 0;
} 