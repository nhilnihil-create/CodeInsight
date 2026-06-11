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

bool comp(vll a,vll b){
    return a[0]>b[0];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N;
    cin>>N;
    vll A(N);
    for(ll i=0;i<N;i++){
        cin>>A[i];
    }
    
    vector<vector<bool>> B(N,vector<bool>(20,0));
    
    for(ll i=0;i<N;i++){
        for(ll j=0;j<20;j++){
            if(A[i]==0)break;
            if(A[i]%2==1)B[i][j]=1;
            else B[i][j]=0;
            A[i]/=2;
        }
    }
    
    /*for(ll i=0;i<N;i++){
        printf("%lld:",i+1);
        for(ll j=0;j<20;j++){
            printf("%d",B[i][19-j]==1);
        }
        printf("\n");
    }*/
    
    ll a=0,b=0;//b<a
    vector<bool> P=B[0];
    ll ans=1;
    while(true){
        ll a_pre=a;
        while(true){
            if(a==N-1) break;
            a++;
            bool ok=true;
            vector<bool> Q=P;
            for(ll i=0;i<20;i++){
                if(Q[i]==1 && B[a][i]==1){
                    ok=false;
                    break;
                }else if(B[a][i]==1){
                    Q[i]=1;
                }
            }
            
            if(ok){
                ans+=a-b+1;
                //printf("%d\n",a-b+1);
                P=Q;
            }else{
                a--;
                break;
            }
        }
        
        if(a==N-1) break;
        
        for(ll i=0;i<20;i++){
            if(B[b][i]==1){
                P[i]=0;
            }
        }
        b++;
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}
