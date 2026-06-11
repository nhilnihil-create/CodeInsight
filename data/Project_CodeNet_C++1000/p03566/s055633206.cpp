#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
 
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
 
const double INF=1e20;
 
int N;
int T[222];
int V[222];
 
double dp[222][222];
 
signed main(){
    cin>>N;
    rep(i,N)cin>>T[i];
    rep(i,N)cin>>V[i];
 
    fill_n(*dp,222*222,-INF);
    dp[0][0]=0;
    rep(i,N){
        rep(j,V[i]+1){
            rep(k,min(V[i],V[i+1])+1){
                if(abs(j-k)>T[i])continue;
                double tmp=dp[i][j];
                int d=abs(j-k);
                int M=max(j,k);
                int m=min(j,k);
                tmp+=(j+k)*0.5*d;
 
                d=T[i]-d;
                if((V[i]-M)*2>d)tmp+=d*d*0.25+M*d;
                else tmp+=(V[i]+M)*(V[i]-M)+(d-(V[i]-M)*2)*V[i];
                chmax(dp[i+1][k],tmp);
            }
        }
    }
 
    printf("%.20f\n",dp[N][0]);
    return 0;
}