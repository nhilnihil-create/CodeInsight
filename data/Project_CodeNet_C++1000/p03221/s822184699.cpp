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

ll digit(long long int n){
    string s;
    s = std::to_string(n);
    return s.size();
}

int main(){
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> Pa(M,0);
    vector<ll> Y(M,0);
    for(ll i=0;i<M;i++){cin>>Pa[i]>>Y[i];Pa[i]--;}
    vector<vector<P>> vec(N, vector<P>(0));
    for(ll i=0;i<M;i++){
        vec[Pa[i]].emplace_back(P(Y[i],i));
    }
    
    for(ll i=0;i<N;i++)sort(vec[i].begin(), vec[i].end());
    vector<P> ans(M);
    for(ll i=0;i<N;i++)
        for(ll j=0;j<vec[i].size();j++){
            ans[vec[i][j].second]=P(i,j);
        }
    for(ll i=0;i<M;i++){
        ll s=ans[i].first+1;
        ll t=ans[i].second+1;
        for(ll j=0;j<6-digit(s);j++)cout<<0;
        cout<<s;
        for(ll j=0;j<6-digit(t);j++)cout<<0;
        cout<<t<<endl;
    }



    return 0;
}