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
    
    
    ll N,K;
    cin>>N>>K;
    vll A(N);
    for(ll i=0;i<N;i++)cin>>A[i];
    
    vll count(N,0);
    for(ll i=0;i<N;i++){
        count[A[i]-1]++;
    }
    
    sort(count.begin(),count.end());
    
    ll ans=0;
    for(ll i=0;i<N-K;i++){
        ans+=count[i];
    }
    cout<<ans<<endl;
    
    return 0;
}
