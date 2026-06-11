#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
int MOD=1000000007;
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
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=2e5+5;

int main(void){
    lint N;
    cin >> N;
    lint ans=0;
    for(int i=1;i<=sqrt(N);i++){
        lint n=N-i;
        if(n%i!=0) continue;
        lint div=n/i;
        if(div<=i) continue;
        ans+=div;
    }
    cout << ans << endl;
}