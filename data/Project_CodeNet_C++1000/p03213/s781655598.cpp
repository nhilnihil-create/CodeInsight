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
    
    vll d(101);
    for(int i=1;i<=N;i++){
        ll A=i;
        for(int j=2;j<=100;j++){
            if(j>A)break;
            while(A%j==0){
                d[j]++;
                A/=j;
            }
        }
    }
    
    int n75=0,n25=0,n15=0,n5=0,n3=0;
    for(int i=0;i<d.size();i++){
        //if(d[i]>0)printf("d[%d]=%d\n",i,d[i]);
        if(d[i]>=3-1) n3++;
        if(d[i]>=5-1) n5++;
        if(d[i]>=15-1) n15++;
        if(d[i]>=25-1) n25++;
        if(d[i]>=75-1) n75++;
    }
    
    //printf("%d,%d,%d,%d,%d\n",n3,n5,n15,n25,n75);
    cout<<n75+n25*max(n3-1,0)+n15*max(n5-1,0)+max(0,n5*(n5-1)/2*(n3-2))<<endl;
    
    return 0;
}
