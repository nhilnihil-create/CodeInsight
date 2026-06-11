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

const ll INF=1LL<<31;

int main(){
    vector<vector<char>> ans(100,vector<char>(100));
    rep(i,100){
        rep(j,100){
            if(j<=49){
                ans[i][j]='.';
            }
            else{
                ans[i][j]='#';
            }
        }
    }
    ll a,b;
    cin >> b >> a;
    a--; b--;
    ll p=0,q=0;
    while(a){
        ans[p][q]='#';
        a--;
        if(p==48){
            p=0;
            q+=2;
        }
        else{
            p+=2;
        }
    }
    ll r=0,s=51;
    while(b){
        ans[r][s]='.';
        b--;
        if(r==48){
            r=0;
            s+=2;
        }
        else{
            r+=2;
        }
    }
    cout << 100 << " " << 100 << endl;
    rep(i,100){
        rep(j,100){
            cout << ans[i][j];
        }
        cout << endl;
    }
} 