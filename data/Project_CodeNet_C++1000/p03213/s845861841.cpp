#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//#include<boost/multiprecision/cpp_dec_float.hpp>
//namespace mp=boost::multiprecision;
//#define mulint mp::cpp_int
//#define mulfloat mp::cpp_dec_float_100
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
//constexpr int MOD=1000000007;
constexpr int MOD=998244353;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
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
    int N;
    cin >> N;
    int div[101]={};
    for(int i=1;i<=N;i++){
        int now=i;
        for(int j=2;j<=N;j++) while(now%j==0) now/=j,div[j]++;
    }
    lint ans=0;
    rep(i,101) div[i]++;
    rep(i,101) if(div[i]>=75) ans++;
    for(int i=1;i<=100;i++) for(int j=i+1;j<=100;j++) if(div[i]>=15 && div[j]>=5) ans++;
    for(int i=1;i<=100;i++) for(int j=i+1;j<=100;j++) if(div[i]>=5 && div[j]>=15) ans++;
    for(int i=1;i<=100;i++) for(int j=i+1;j<=100;j++) if(div[i]>=3 && div[j]>=25) ans++;
    for(int i=1;i<=100;i++) for(int j=i+1;j<=100;j++) if(div[i]>=25 && div[j]>=3) ans++;
    for(int i=1;i<=100;i++) for(int j=i+1;j<=100;j++) for(int k=j+1;k<=100;k++) if(div[i]>=3 && div[j]>=5 && div[k]>=5) ans++;
    for(int i=1;i<=100;i++) for(int j=i+1;j<=100;j++) for(int k=j+1;k<=100;k++) if(div[i]>=5 && div[j]>=3 && div[k]>=5) ans++;
    for(int i=1;i<=100;i++) for(int j=i+1;j<=100;j++) for(int k=j+1;k<=100;k++) if(div[i]>=5 && div[j]>=5 && div[k]>=3) ans++;
    cout << ans << endl;
}