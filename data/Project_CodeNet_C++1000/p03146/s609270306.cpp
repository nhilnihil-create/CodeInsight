#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using Tup = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fl cout<<flush;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld pi=3.141592653589793238;



signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll S;
    cin >> S;
    auto F=[](ll &n){
        if(n%2==0)return n/2;
        else return 3*n+1;
    };
    vector<ll> vec(1000001);
    vec[0]=S;
    for(ll i=1;i<1000001;++i)vec[i]=F(vec[i-1]);
    Map M;
    for(ll i=0;i<1000001;++i){
        M[vec[i]]++;
        if(M[vec[i]]>1){
            prt(i+1)fl return 0;
        }
    }


    return 0;
}
