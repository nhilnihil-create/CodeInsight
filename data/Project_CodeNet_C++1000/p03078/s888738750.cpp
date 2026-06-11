#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(long long i=0;i<n;++i)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll INF=(1ll<<60);
constexpr ll mod=1000000007;
constexpr double pi=3.14159265358979323846;
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll X,Y,Z,K;cin>>X>>Y>>Z>>K;
    vector<ll> A(X),B(Y),C(Z),ans;

    rep(i,X){
        cin>>A[i];
    }
    rep(i,Y){
        cin>>B[i];
    }
    rep(i,Z){
        cin>>C[i];
    }

    sort(A.begin(),A.end(),greater<ll>());
    sort(B.begin(),B.end(),greater<ll>());
    sort(C.begin(),C.end(),greater<ll>());

    vector<ll> vecab;
    rep(i,X){
        rep(j,Y){
            vecab.push_back(A[i]+B[j]);
        }
    }
    sort(vecab.begin(),vecab.end(),greater<ll>());

    rep(i,min(K,X*Y)){
        rep(j,Z){
            ans.push_back(vecab[i]+C[j]);
        }
    }

    sort(ans.begin(),ans.end(),greater<ll>());

    rep(i,K){
        cout<<ans[i]<<endl;
    }
    return 0;
}