#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

void output(pint P){
    int p = P.first, y = P.second;
    string sp = to_string(p), sy = to_string(y);
    while(sp.size()!=6){
        sp = '0' + sp;
    }
    while(sy.size()!=6){
        sy = '0' + sy;
    }
    cout<<sp<<sy<<endl;
}

int main(){
    int N,M; cin>>N>>M;
    vector<pll> Y;//y,ind
    vector<int> P(M);
    rep(i,M){
        cin>>P[i];
        ll y; cin>>y;
        Y.push_back({y,i});
    }
    sort(Y.begin(),Y.end());
    vector<pint> R(M); // P/jyunn
    vector<int> C(N,0);
    rep(i,M){
        ll ind = Y[i].second;
        ll p = P[ind];
        int c = C[p]+1;
        C[p]++;
        R[ind] = {p,c};
    }
    rep(i,M) output(R[i]);
}
