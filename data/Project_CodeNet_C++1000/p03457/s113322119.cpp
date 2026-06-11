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

int main(){
    ll n;
    cin >> n;
    ll t=0;
    ll x=0,y=0;
    bool ok=true;
    rep(i,n){
        ll cur,nx,ny;
        cin >> cur >> nx >> ny;
        ll d=abs(x-nx)+abs(y-ny);
        ll dt=cur-t;
        if(d<=dt && (dt-d)%2==0){
            t=cur;
            x=nx;
            y=ny;
        }
        else{
            ok=false;
            break;
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
} 