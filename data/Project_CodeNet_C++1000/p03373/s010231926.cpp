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
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;



int main(){
    ll A;
    cin >> A;
    ll B;
    cin >> B;
    ll C;
    cin >> C;
    ll X;
    cin >> X;
    ll Y;
    cin >> Y;
    ll ans=INF;
    for(ll i=0;i<=max(X,Y)+10;i++){
        chmin(ans,max(0LL,A*(X-i))+max(0LL,B*(Y-i))+2*C*i)
    ;}
    print(ans);
    return 0;
}
