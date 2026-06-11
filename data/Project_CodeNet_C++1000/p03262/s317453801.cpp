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

ll gcd(ll a,ll b) {
    while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
    }
    return a;
}

int main(){
    ll N;
    cin >> N;
    ll X;
    cin >> X;
    vector<ll> x(N,0);
    for(ll i=0;i<N;i++)cin>>x[i];
    vector<ll> y(N,0);
    for(ll i=0;i<N;i++)y[i]=llabs(x[i]-X);
    ll ans=y[0];
    for(ll i=0;i<N;i++){
        ans=gcd(ans,y[i]);
    }
    print(ans)

    return 0;
}