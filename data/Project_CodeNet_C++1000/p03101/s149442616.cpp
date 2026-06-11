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

ll F(ll x){
    if(x<=0)return 1;
    if(x==1)return 2;
    if(x==2)return 3;
    if(x==3)return 5;
    if(x==4)return 8;
    if(x==5)return 13;
    if(x==6)return 21;
    if(x==7)return 34;
    if(x==8)return 55;
}


int main(){
    ll H;
    cin >> H;
    ll W;
    cin >> W;
    ll h;
    cin >> h;
    ll w;
    cin >> w;
    print((H-h)*(W-w))
    return 0;
}