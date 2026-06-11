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

const ll INF=1e9+7;

int main(){
    ll h,w;
    cin >> h >> w;
    vector<vector<char>> s(h,vector<char>(w));
    ll ans=0;
    rep(i,h){
        rep(j,w){
            cin >> s[i][j];
            if(s[i][j]=='.') ans++;
        }
    }
    vector<vector<ll>> d(h,vector<ll>(w,INF));
    ll dx[4]={-1,1,0,0};
    ll dy[4]={0,0,-1,1};
    queue<pll> que;
    d[0][0]=1;
    que.push(make_pair(0,0));
    while(!que.empty()){
        pll x=que.front();
        que.pop();
        rep(i,4){
            ll nx=x.fi+dx[i];
            ll ny=x.se+dy[i];
            if(0<=nx && nx<=h-1 && 0<=ny && ny<=w-1 && d[nx][ny]==INF && s[nx][ny]=='.'){
                d[nx][ny]=d[x.fi][x.se]+1;
                que.push(make_pair(nx,ny));
            }
        }
    }
    if(d[h-1][w-1]==INF){
        cout << -1 << endl;
    }
    else{
        ans-=d[h-1][w-1];
        cout << ans << endl;
    }
} 
