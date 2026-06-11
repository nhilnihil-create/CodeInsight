#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;



int main(){
    ll N;
    cin >> N;
    string A;
    cin >> A;
    string B;
    cin >> B;
    string C;
    cin >> C;
    ll count=0;
    vector<char> yose(N,' ');
    for(ll i=0;i<N;i++){
        if(A[i]==B[i])yose[i]=A[i];
        else if(B[i]==C[i])yose[i]=B[i];
        else yose[i]=A[i];
    ;}
    for(ll i=0;i<N;i++){
        if(A[i]!=yose[i])count++;
    ;}
    for(ll i=0;i<N;i++){
        if(B[i]!=yose[i])count++;
    ;}
    for(ll i=0;i<N;i++){
        if(C[i]!=yose[i])count++;
    ;}
    cout<<count<<endl;
    return 0;
}
