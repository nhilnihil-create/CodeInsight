#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<P,ll>;
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
    vector<ll> A(5,0);
    for(ll i=0;i<5;i++)cin>>A[i];
    vector<ll> B(5,0);
    ll ans=0;
    for(ll i=0;i<5;i++)ans+=((A[i]+9)/10)*10;
    for(ll i=0;i<5;i++)B[i]=(10-(A[i]%10))%10;
    sort(B.begin(), B.end());
    print(ans-B[4])

    return 0;
}