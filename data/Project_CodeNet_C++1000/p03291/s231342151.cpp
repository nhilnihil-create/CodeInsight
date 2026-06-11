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
    ll A=0,AB=0,ABC=0,D=1;
    ll n=S.size();
    for(ll i=0;i<n;i++){
        if(S[i]=='?'){
            ABC=(ABC*3+AB)%MOD;
            AB=(AB*3+A)%MOD;
            A=(A*3+D)%MOD;
            D=(D*3)%MOD;
        }
        else if(S[i]=='A'){
            A=(A+D)%MOD;
        }
        else if(S[i]=='B'){
            AB=(AB+A)%MOD;
        }
        else if(S[i]=='C'){
            ABC=(ABC+AB)%MOD;
        }
    }
    print(ABC)
    return 0;
}