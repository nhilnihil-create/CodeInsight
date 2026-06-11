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

bool comp0(vll a,vll b){
    return a[0]+a[1]+a[2]>b[0]+b[1]+b[2];
}

bool comp1(vll a,vll b){
    return a[0]-a[1]+a[2]>b[0]-b[1]+b[2];
}

bool comp2(vll a,vll b){
    return -a[0]+a[1]+a[2]>-b[0]+b[1]+b[2];
}

bool comp3(vll a,vll b){
    return a[0]+a[1]-a[2]>b[0]+b[1]-b[2];
}

bool comp4(vll a,vll b){
    return -a[0]-a[1]+a[2]>-b[0]-b[1]+b[2];
}

bool comp5(vll a,vll b){
    return -a[0]+a[1]-a[2]>-b[0]+b[1]-b[2];
}

bool comp6(vll a,vll b){
    return a[0]-a[1]-a[2]>b[0]-b[1]-b[2];
}

bool comp7(vll a,vll b){
    return -a[0]-a[1]-a[2]>-b[0]-b[1]-b[2];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N,M;
    cin>>N>>M;
    vvll xyz(N,vll(3));
    for(ll i=0;i<N;i++)cin>>xyz[i][0]>>xyz[i][1]>>xyz[i][2];
    
    ll ans[8]={};
    ll sum1,sum2,sum0;
    
    sum1=0;sum2=0;sum0=0;
    sort(xyz.begin(),xyz.end(),comp0);
    for(ll i=0;i<M;i++){
        sum0+=xyz[i][0];
        sum1+=xyz[i][1];
        sum2+=xyz[i][2];
    }
    ans[0]=abs(sum0)+abs(sum1)+abs(sum2);
    sum1=0;sum2=0;sum0=0;
    sort(xyz.begin(),xyz.end(),comp1);
    for(ll i=0;i<M;i++){
                sum0+=xyz[i][0];
        sum1+=xyz[i][1];
        sum2+=xyz[i][2];
    }
    ans[1]=abs(sum0)+abs(sum1)+abs(sum2);
    sum1=0;sum2=0;sum0=0;
    sort(xyz.begin(),xyz.end(),comp2);
    for(ll i=0;i<M;i++){
                sum0+=xyz[i][0];
        sum1+=xyz[i][1];
        sum2+=xyz[i][2];
    }
    ans[2]=abs(sum0)+abs(sum1)+abs(sum2);
    sum1=0;sum2=0;sum0=0;
    sort(xyz.begin(),xyz.end(),comp3);
    for(ll i=0;i<M;i++){
                sum0+=xyz[i][0];
        sum1+=xyz[i][1];
        sum2+=xyz[i][2];
    }
    ans[3]=abs(sum0)+abs(sum1)+abs(sum2);
    sum1=0;sum2=0;sum0=0;
    sort(xyz.begin(),xyz.end(),comp4);
    for(ll i=0;i<M;i++){
                sum0+=xyz[i][0];
        sum1+=xyz[i][1];
        sum2+=xyz[i][2];
    }
    ans[4]=abs(sum0)+abs(sum1)+abs(sum2);
    sum1=0;sum2=0;sum0=0;
    sort(xyz.begin(),xyz.end(),comp5);
    for(ll i=0;i<M;i++){
                sum0+=xyz[i][0];
        sum1+=xyz[i][1];
        sum2+=xyz[i][2];
    }
    ans[5]=abs(sum0)+abs(sum1)+abs(sum2);
    sum1=0;sum2=0;sum0=0;
    sort(xyz.begin(),xyz.end(),comp6);
    for(ll i=0;i<M;i++){
                sum0+=xyz[i][0];
        sum1+=xyz[i][1];
        sum2+=xyz[i][2];
    }
    ans[6]=abs(sum0)+abs(sum1)+abs(sum2);
    sum1=0;sum2=0;sum0=0;
    sort(xyz.begin(),xyz.end(),comp7);
    for(ll i=0;i<M;i++){
                sum0+=xyz[i][0];
        sum1+=xyz[i][1];
        sum2+=xyz[i][2];
    }
    ans[7]=abs(sum0)+abs(sum1)+abs(sum2);
    
    ll max=0;
    for(ll i=0;i<8;i++){
        if(ans[i]>max)max=ans[i];
    }
    cout<<max<<endl;
        
    return 0;
}
