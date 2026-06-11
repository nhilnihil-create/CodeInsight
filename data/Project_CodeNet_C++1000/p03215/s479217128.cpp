#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
typedef unsigned long long int ull;
typedef long long lint;

int main(void){
    lint N,K;
    cin >> N >> K;
    lint A[N];
    rep(i,N) cin >> A[i];
    lint sum[N+1]={};
    rep(i,N) sum[i+1]=sum[i]+A[i];
    lint all=(N*(N+1))/2;
    lint sub[all];
    lint now=0;
    for(int i=0;i<N;i++) for(int j=i+1;j<=N;j++) sub[now]=sum[j]-sum[i],now++;
    lint ans=0;
    for(int i=50;i>=0;i--){
        int count=0;
        rep(j,all) if(((ans+(1LL<<i))&sub[j])==(ans+(1LL<<i))) count++;
        if(count>=K) ans+=1LL<<i;
    }
    cout << ans << endl;
}