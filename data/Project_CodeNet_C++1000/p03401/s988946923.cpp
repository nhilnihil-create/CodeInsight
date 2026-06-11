#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    ll N;cin>>N;
    vector<ll>A(N+2,0);
    vector<ll>Ans(N);
    for(int i=1;i<N+1;i++){
        cin>>A[i];
    }
    ll cost=0;
    rep(i,N+1){
        cost+=abs(A[i]-A[i+1]);
    }
    for(int i=1;i<=N;i++){
        Ans[i-1]=cost-abs(A[i]-A[i-1])-abs(A[i]-A[i+1])+abs(A[i+1]-A[i-1]);
    }
    rep(i,N){
        cout<<Ans[i]<<endl;
    }
}