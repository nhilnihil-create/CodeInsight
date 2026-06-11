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
#define ALL(X) X.begin(),X.end()
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
    
    ll N,C;
    cin>>N>>C;
    vll s(N),t(N),c(N);
    for(ll i=0;i<N;i++)cin>>s[i]>>t[i]>>c[i];
    
    vector<vector<bool>> TV(C,vector<bool>(100001,false));
    for(ll i=0;i<N;i++){
        for(ll j=s[i]-1;j<t[i];j++){
            TV[c[i]-1][j]=true;
        }
    }
    
    ll ans=1;
    for(ll i=0;i<100001;i++){
        ll count=0;
        for(ll j=0;j<C;j++){
            if(TV[j][i])count++;
        }
        chmax(ans,count);
    }
    cout<<ans<<endl;
    
    return 0;
}
