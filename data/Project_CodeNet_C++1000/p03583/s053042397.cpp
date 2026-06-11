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
const ll mod=1e9+7;

int main(){
    ll N;
    cin >> N;
    for(ll n=1;n<=3500;n++){
        for(ll w=1;w<=3500;w++){
            if(4*n*w-N*(n+w)>0){
                ll le=0,ri=3500;
                while(ri-le>1){
                    ll h=(ri+le)/2;
                    if((4*n*w-N*(n+w))*h-N*n*w>=0) ri=h;
                    else le=h;
                }
                if((4*n*w-N*(n+w))*ri-N*n*w==0){
                    cout << ri << " " << n << " " << w << endl;
                    return 0;
                }
            }
            else{
                ll le=0,ri=3500;
                while(ri-le>1){
                    ll h=(ri+le)/2;
                    if((4*n*w-N*(n+w))*h-N*n*w<=0) ri=h;
                    else le=h;
                }
                if((4*n*w-N*(n+w))*ri-N*n*w==0){
                    cout << ri << " " << n << " " << w << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}

