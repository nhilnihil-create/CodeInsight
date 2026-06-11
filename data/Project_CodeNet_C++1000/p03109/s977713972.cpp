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


int main(){
    string S;
    cin >> S;
    ll Y=stoll(S.substr(0,4));
    ll M=stoll(S.substr(5,2));
    ll D=stoll(S.substr(8,2));
    vector<ll> vec={Y,M,D};
    vector<ll> vec2={2019,4,30};
    if(vec<=vec2)print("Heisei")
    else print("TBD")

    return 0;
}