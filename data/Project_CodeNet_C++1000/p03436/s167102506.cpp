#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<v<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

vector<vector<char>> S(60, vector<char>(60));
vector<vector<bool>> check(60, vector<bool>(60, 0));
ll H,W;

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    cin>>H>>W;
    ll bcou=0;
    for(ll i=0;i<H;++i)
        for(ll j=0;j<W;++j){
            cin>>S[i][j];
            if(S[i][j]=='#')bcou++;
        }
    vector<ll> dx={1,0,-1,0};
    vector<ll> dy={0,1,0,-1};
    queue<P> que;
    que.emplace(P(0,0));
    vector<vector<ll>> d(60, vector<ll>(60, INF));
    d[0][0]=0;
    while(!que.empty()){
        P z=que.front();
        que.pop();
        ll x=z.first;
        ll y=z.second;
        for(ll i=0;i<4;++i){
            ll nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&nx<H&&ny>=0&&ny<W&&d[nx][ny]==INF&&S[nx][ny]=='.'){
                d[nx][ny]=d[x][y]+1;
                que.emplace(P(nx,ny));
            }
        }
    }
    if(d[H-1][W-1]==INF){
        prt(-1)return 0;
    }
    prt(H*W-bcou-d[H-1][W-1]-1)
    

    return 0;
}
