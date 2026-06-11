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
    ll Q;
    cin >> Q;
    vector<ll> A(Q,0);
    vector<ll> B(Q,0);
    for(ll i=0;i<Q;i++){
        cin>>A[i]>>B[i];
        ll ab=A[i]*B[i];
        ll x=sqrt(ab);
        if(A[i]==B[i]){print(2*x-2) continue;}
        if(x*x==ab){x--;}
        if(x*(x+1)<ab)print(2*x-1)
        else print(2*x-2)
    }

    return 0;
}
