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

int main(){
    int X,Y,Z,K; cin>>X>>Y>>Z>>K;
    vector<ll> A(X),B(Y),C(Z);
    rep(i,X)cin>>A[i];
    rep(i,Y)cin>>B[i];
    rep(i,Z)cin>>C[i];
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());
    sort(C.rbegin(),C.rend());
    vector<ll> R;
    rep(i,X){
        rep(j,Y){
            if((i+1)*(j+1)>K)continue;
            rep(k,Z){
                if((i+1)*(j+1)*(k+1)>K)continue;
                R.push_back(A[i]+B[j]+C[k]);
            }
        }
    }
    sort(R.rbegin(),R.rend());
    rep(i,K)cout<<R[i]<<endl;
}
