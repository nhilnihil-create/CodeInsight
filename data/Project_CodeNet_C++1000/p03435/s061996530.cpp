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
    vector<vector<ll>> c(3,vector<ll>(3));
    rep(i,3){
        rep(j,3){
            cin >> c[i][j];
        }
    }
    bool ans=true;
    rep(i,2){
        bool ok=true;
        ll v=0;
        rep(j,3){
            if(j==0){
                v=c[i+1][j]-c[i][j];
            }
            else{
                if(c[i+1][j]-c[i][j]!=v){
                    ok=false;
                }
            }
        }
        if(!ok){
            ans=false;
        }
    }
    rep(i,2){
        bool ok=true;
        ll v=0;
        rep(j,3){
            if(j==0){
                v=c[j][i+1]-c[j][i];
            }
            else{
                if(c[j][i+1]-c[j][i]!=v){
                    ok=false;
                }
            }
        }
        if(!ok){
            ans=false;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
} 