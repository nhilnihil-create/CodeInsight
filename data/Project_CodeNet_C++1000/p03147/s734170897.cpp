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

ll N;

ll F(vl vec){
    ll count=0;
    for(ll i=1;i<N;i++){
        if(vec[i-1]==0&&vec[i])count++;
    }
    if(vec[0])count++;
    if(count==0)return 0;
    for(ll i=0;i<N;i++)vec[i]=max(vec[i]-1,0LL);
    return count+F(vec);

}

int main(){
    cin >> N;
    vector<ll> H(N,0);
    vector<ll> M(N,0);
    for(ll i=0;i<N;i++)cin>>H[i];
    print(F(H))
    return 0;
}