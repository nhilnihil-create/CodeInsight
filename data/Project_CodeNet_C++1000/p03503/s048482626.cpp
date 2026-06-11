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
    
    vvvll F(N,vvll(5,vll(2)));
    for(ll i=0;i<N;i++)for(ll j=0;j<5;j++)cin>>F[i][j][0]>>F[i][j][1];
    vvll P(N,vll(11));
    for(ll i=0;i<N;i++)for(ll j=0;j<11;j++)cin>>P[i][j];
    ll ans=-LLMAX;
    for(ll i=1;i<pow(2,10);i++){
        bool J[5][2];
        ll ii=i;
        for(ll k=0;k<5;k++){
            for(ll j=0;j<2;j++){
                if(ii%2==0) J[k][j]=false;
                else J[k][j]=true;
                ii/=2;
            }
        }
        
        vll count(N,0);
        for(ll j=0;j<N;j++){
            for(ll k=0;k<5;k++){
                for(ll l=0;l<2;l++){
                    if(F[j][k][l]==1 && J[k][l]==1){
                        //printf("cccccount[%d]=%d\n",j,count[j]);
                        count[j]++;
                    }
                }
            }
        }
        
        ll sum=0;
        for(ll j=0;j<N;j++){
            sum+=P[j][count[j]];
           // printf("count[%d]=%d\n",j,count[j]);
            //p//rintf("P[%d][%d]=%d\n",j,count[j],P[j][count[j]]);
        }
        //printf("sum=%d\n",sum);
        chmax(ans,sum);
    }
    cout<<ans<<endl;
    
    return 0;
}
