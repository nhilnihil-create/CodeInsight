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

int main(){
    ll h,w;
    cin >> h >> w;
    ll dx[4]={-1,1,0,0};
    ll dy[4]={0,0,-1,1};
    vector<vector<char>> s(h,vector<char>(w));
    rep(i,h){
        rep(j,w){
            cin >> s[i][j];
        }
    }
    bool ans=true;
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#'){
                bool ok=false;
                rep(k,4){
                    ll nx=i+dx[k];
                    ll ny=j+dy[k];
                    if(0<=nx && nx<=h-1 && 0<=ny && ny<=w-1 && s[nx][ny]=='#'){
                        ok=true;
                        break;
                    }
                }
                if(!ok){
                    ans=false;
                }
            }
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
} 