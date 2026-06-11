#include<bits/stdc++.h>
using namespace std;
using ll = long long;
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


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    map<char,ll> M;
    for(ll i=0;i<N;++i){
        string S;
        cin >> S;
        M[S[0]]++;
    }
    vector<char> vec={'M','A','R','C','H'};
    ll ans=0;
    for(ll i=0;i<3;++i)
        for(ll j=i+1;j<4;++j)
            for(ll k=j+1;k<5;++k){
                ans+=(M[vec[i]]*M[vec[j]]*M[vec[k]]);
            }
    prt(ans)
    
    return 0;
}
