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
    
    ll N;
    cin>>N;
    vll C(N-1),S(N-1),F(N-1);
    for(ll i=0;i<N-1;i++)cin>>C[i]>>S[i]>>F[i];
    
    for(ll i=0;i<N;i++){
        ll time=0;
        for(ll j=i;j<N-1;j++){
            if(time<S[j]){
                time=S[j]+C[j];
            }else{
                time=(ll)ceil((double)time/(double)F[j])*F[j]+C[j];
            }
        }
        cout<<time<<endl;
    }
    
    return 0;
}
