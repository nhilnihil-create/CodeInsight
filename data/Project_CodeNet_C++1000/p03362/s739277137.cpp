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
    ll a=6;
    for(ll i=0;i<N;i++){
        while(true){
            ll j_max=sqrt(a);
            bool ok=true;
            for(ll j=2;j<=j_max;j++){
                if(a%j==0){
                    ok=false;
                    break;
                }
            }
            if(ok){
                printf("%d ",a);
                a+=5;
                break;
            }
            a+=5;
        }
    }
    
    return 0;
}
