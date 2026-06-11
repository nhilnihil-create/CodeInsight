#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;
ll N;
vector<vector<char>> S(300, vector<char>(300, ' '));
vector<vector<int>> check(300, vector<int>(300, -1));

int F(ll A, ll B){
    if(A>0&&B>0&&check[A-1][B-1]!=-1)return check[A][B]=check[A-1][B-1];
    for(ll i=0;i<N;i++){
     for(ll j=i;j<N;j++){
         if(S[(i+A)%N][(j+B)%N]!=S[(j+A)%N][(i+B)%N])return check[A][B]=0;
     ;}
    ;}
    return check[A][B]=1;
}

int main(){
    cin>>N;
    for(ll i=0;i<N;i++){
     for(ll j=0;j<N;j++){
         cin>>S[i][j];
     ;}
    ;}
    ll ans=0;
    for(ll i=0;i<N;i++){
     for(ll j=0;j<N;j++){
         if(F(i,j))ans++;
     ;}
    ;}
    cout<<ans<<endl;
    return 0;
}
