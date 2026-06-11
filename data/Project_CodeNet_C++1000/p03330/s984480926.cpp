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
    
    ll N,C;
    cin>>N>>C;
    vvll D(C,vll(C));
    for(ll i=0;i<C;i++){
        for(ll j=0;j<C;j++){
            cin>>D[i][j];
        }
    }
    vvll c(N,vll(N));
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            cin>>c[i][j];
            c[i][j]--;
        }
    }
    
    vvll count(3,vll(C,0));
    
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            count[(i+j)%3][c[i][j]]++;
        }
    }
    
    vvll U(3,vll(C,0));
    for(int i=0;i<3;i++){
        for(ll j=0;j<C;j++){
            U[i][j]=0;
            for(ll k=0;k<C;k++){
                if(k==j)continue;
                U[i][j]+=count[i][k]*D[k][j];
            }
        }
    }
    
    ll ans=LLMAX;
    for(ll i=0;i<C;i++){
        for(ll j=0;j<C;j++){
            for(ll k=0;k<C;k++){
                if(i==j || j==k || k==i)continue;
                if(U[0][i]+U[1][j]+U[2][k]<ans)ans=U[0][i]+U[1][j]+U[2][k];
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
