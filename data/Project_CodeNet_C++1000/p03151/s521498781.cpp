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
    vector<ll> A(N,0);
    vector<ll> B(N,0);
    for(ll i=0;i<N;i++)cin>>A[i];
    for(ll i=0;i<N;i++)cin>>B[i];
    ll suma=0,sumb=0;
    for(ll i=0;i<N;i++){
        suma+=A[i];
        sumb+=B[i];
    }
    if(sumb>suma){print(-1)return 0;}
    vector<ll> D(N,0);
    ll minus=0;ll count=0;
    for(ll i=0;i<N;i++){D[i]=A[i]-B[i];if(D[i]<0){minus-=D[i];count++;}}
    sort(D.rbegin(), D.rend());
    ll sum=0;
    for(ll i=0;i<N;i++){
        if(sum>=minus)break;
        sum+=D[i];count++;
    }
    print(count)
    
    return 0;
}