#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll K;
    cin >> K;
    vector<ll> A(K,0);
    for(ll i=0;i<K;i++){
        cin>>A[i]
    ;}
    ll x=INF;
    for(ll i=0;i<K;i++){
        x=A[i]*(x/A[i])
    ;}
    if(x<2){
        cout<<-1<<endl;return 0;
    }
    ll L=1,R=INF;
    while(L+1<R){
        ll m=(L+R)/2;
        x=m;
        for(ll i=0;i<K;i++){
        x=A[i]*(x/A[i])
        ;}
        if(x>2)R=m;
        else L=m;
    }
    ll Max=L;

    L=1,R=INF;
    while(L+1<R){
        ll m=(L+R)/2;
        x=m;
        for(ll i=0;i<K;i++){
        x=A[i]*(x/A[i])
        ;}
        if(x>=2)R=m;
        else L=m;
    }
    ll Min=R;

    if(Min>Max){cout<<-1<<endl;return 0;}

    cout<<Min<<" "<<Max<<endl;

    return 0;
}
