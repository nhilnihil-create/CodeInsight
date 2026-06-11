#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll,ll>;
using um = unordered_map<ll,ll>;
#define fl cout<<flush;
#define endl '\n'
template <typename T> inline void prt(T v){cout<<v<<'\n';}
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1e9+7;
const ll MOD2=998244353;
const ld pi=3.14159265358979323846;
const ld eps=1e-10;

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll L=0;
    ll R=N-1;
    prt(L);fl
    string LL;
    cin >> LL;if(LL=="Vacant")return 0;
    prt(R);fl 
    string RR;
    cin >> RR;if(RR=="Vacant")return 0;
    for(ll i=0;i<18;++i){
        ll M=(L+R)/2;
        prt(M);fl
        string S;
        cin >> S;
        if(S=="Vacant")return 0;
        if(R%2!=M%2&&S==RR){
            L=M;LL=S;continue;
        }
        else if(R%2==M%2&&S!=RR){
            L=M;LL=S;continue;
        }
        else {
            R=M;RR=S;continue;
        }
    }

    return 0;
}

