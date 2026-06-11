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
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int main(void){
    lint X,Y,Z,K;
    cin >> X >> Y >> Z >> K;
    lint A[X],B[Y],C[Z];
    rep(i,X) cin >> A[i];
    rep(i,Y) cin >> B[i];
    rep(i,Z) cin >> C[i];
    lint N=X*Y;
    lint cake[N];
    rep(i,X) rep(j,Y) cake[i*Y+j]=A[i]+B[j];
    sort(cake,cake+N,greater<lint>());
    lint n=min(3000LL,X*Y);
    lint nw[n];
    rep(i,n) nw[i]=cake[i];
    lint ans[n*Z];
    rep(i,n) rep(j,Z) ans[i*Z+j]=nw[i]+C[j];
    sort(ans,ans+n*Z,greater<lint>());
    rep(i,K) cout << ans[i] << endl;
}