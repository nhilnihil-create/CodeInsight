#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

ll H,W;

vector<vector<char>> A(1000, vector<char>(1000));
vector<vector<ll>> dp(1000, vector<ll>(1000, -1));

int main(){
    cin >> H;
    cin >> W;
    for(ll i=0;i<H;i++)
        for(ll j=0;j<W;j++)cin>>A[i][j];
    
    queue<P> qu;
    for(ll i=0;i<H;i++)
        for(ll j=0;j<W;j++){
            if(A[i][j]=='#')qu.emplace(P(i,j));
        }
    qu.emplace(P(INF,INF));
    ll count=0;
    while(qu.size()>1){
        P x=qu.front();qu.pop();
        ll i=x.first; ll j=x.second;
        if(x==P(INF,INF)){
            count++;qu.emplace(P(INF,INF));continue;
        }
        
        if(i>0&&A[i-1][j]=='.'){qu.emplace(P(i-1,j));A[i-1][j]='#';}
        if(j>0&&A[i][j-1]=='.'){qu.emplace(P(i,j-1));A[i][j-1]='#';}
        if(i<H-1&&A[i+1][j]=='.'){qu.emplace(P(i+1,j));A[i+1][j]='#';}
        if(j<W-1&&A[i][j+1]=='.'){qu.emplace(P(i,j+1));A[i][j+1]='#';}

    }
    print(count);


    return 0;
}