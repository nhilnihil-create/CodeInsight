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
    ll N;
    cin >> N;
    vector<ll> A(N+1,0);
    for(ll i=0;i<N;i++)cin>>A[i+1];
    vector<ll> until(N+1,0);
    for(ll i=1;i<=N;i++)until[i]=until[i-1]+A[i];
    Map M;
    for(ll i=0;i<=N;i++)M[until[i]]++;
    ll ans=0;
    for(auto p: M){
        ll x=p.second;
        ans+=x*(x-1)/2;
    }
    print(ans)
    return 0;
}