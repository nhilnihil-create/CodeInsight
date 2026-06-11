#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>

template<typename T> bool chmax(T &a,T b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

template<typename T> bool chmin(T &a,T b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}

using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=1001001000;
const ll LLMAX=1010010010010010000;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N;
    cin>>N;
    string S;
    cin>>S;
    
    vll E(N),W(N);
    if(S[0]=='E')E[0]=1;
    else W[0]=1;
    for(ll i=1;i<N;i++){
        if(S[i]=='E'){
            E[i]=E[i-1]+1;
            W[i]=W[i-1];
        }else{
            E[i]=E[i-1];
            W[i]=W[i-1]+1;
        }
    }
    
    ll ans=LLMAX;
    for(ll i=0;i<N;i++){
        if(i==0){
            chmin(ans,E[N-1]-E[0]);
            //printf("%d:%d\n",i,E[N-1]-E[0]);
        }else if(i==N-1){
            chmin(ans,W[N-2]);
            //printf("%d:%d\n",i,W[N-2]);
        }else{
            chmin(ans,W[i-1]+E[N-1]-E[i]);
            //printf("%d:%d\n",i,W[i-1]+E[N-1]-E[i]);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
