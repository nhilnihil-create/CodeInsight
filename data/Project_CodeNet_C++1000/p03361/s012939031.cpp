#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl
#define first(v) get<0>(v)
#define second(v) get<1>(v)
#define third(v) get<2>(v)
template <typename T> bool chmax(T &a, T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll H;
    cin >> H;
    ll W;
    cin >> W;
    vector<vector<char>> S(H, vector<char>(W));
    for(ll i=0;i<H;i++){
       for(ll j=0;j<W;j++){
           cin>>S[i][j]
       ;}
    ;}
    bool ans=1;
    for(ll i=0;i<H;i++){
       for(ll j=0;j<W;j++){
           if(S[i][j]=='#'){
               if(i-1>=0&&S[i-1][j]=='#')continue;
               if(i+1<H&&S[i+1][j]=='#')continue;
               if(j-1>=0&&S[i][j-1]=='#')continue;
               if(j+1<W&&S[i][j+1]=='#')continue;
               ans=0;
           }
       ;}
    ;}
    if(ans)print("Yes");
    else print("No");

    return 0;
}
