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
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    int now,cnt=1;
    vector<pint> stand;
    rep(i,N){
        if(S[i]=='0') now=0;
        else now=1;
        while(i<N && S[i]==S[i+1]) cnt++,i++;
        stand.push_back(pint(cnt,now));
        cnt=1;
    }
    int sum[stand.size()+1]={};
    int ans=0;
    rep(i,stand.size()) sum[i+1]=sum[i]+stand[i].fi;
    rep(i,stand.size()){
        int end;
        if(stand[i].se==0) end=i+2*K;
        else end=i+2*K+1;
        end=min((int)stand.size(),end);
        ans=max(ans,sum[end]-sum[i]);
    }
    cout << ans << endl;
}