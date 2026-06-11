#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
constexpr int MOD=1000000007;
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

vector<lint> bitall(lint num,lint base,lint keta){
    vector<lint> res;
    while(num>0){
        res.push_back(num%base);
        num/=base;
    }
    while(res.size()<keta) res.push_back(0);
    reverse(res.begin(),res.end());
    return res;
}

int main(void){
    lint N,a,b,c;
    cin >> N >> a >> b >> c;
    lint L[N];
    rep(i,N) cin >> L[i];
    lint rem=N-3;
    lint all=pow(4,rem);
    lint ans=LINF;
    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) for(int k=j+1;k<N;k++){
        vector<lint> A,B;
        rep(l,N){
            if(l==i || l==j || l==k) A.push_back(L[l]);
            else B.push_back(L[l]);
        }
        rep(l,all){
            lint base[3];
            base[0]=A[0],base[1]=A[1],base[2]=A[2];
            vector<lint> now=bitall(l,4,N-3);
            lint add=0;
            rep(m,N-3){
                if(now[m]==1) base[0]+=B[m],add+=10;
                else if(now[m]==2) base[1]+=B[m],add+=10;
                else if(now[m]==3) base[2]+=B[m],add+=10;
            }
            sort(base,base+3,greater<lint>());
            ans=min(ans,abs(base[0]-a)+abs(base[1]-b)+abs(base[2]-c)+add);
        }
    }
    cout << ans << endl;
}