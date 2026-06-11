#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second　//pairの二つ目の要素

int n;
int c[]={0,0,0,0};
vector<vector<vector<double>>> dp;
vector<vector<vector<int>>> flag;
double f(int c1, int c2, int c3){
    if(flag[c1][c2][c3]) return dp[c1][c2][c3];
    flag[c1][c2][c3]=1;
    if(c1==0 && c2==0 && c3==0) return 0.;
    double ret=1./(1.-(double)(n-c1-c2-c3)/n);
    if(c1>0) ret+=f(c1-1,c2,c3)  *(double)c1/n/(1.-(double)(n-c1-c2-c3)/n);
    if(c2>0) ret+=f(c1+1,c2-1,c3)*(double)c2/n/(1.-(double)(n-c1-c2-c3)/n);
    if(c3>0) ret+=f(c1,c2+1,c3-1)*(double)c3/n/(1.-(double)(n-c1-c2-c3)/n);
    dp[c1][c2][c3]=ret;
    return ret;
}

int main(){
    cin>>n;
    rep(i,n){
        int a;
        cin>>a;
        c[a]++;
    }
    dp.resize(n+1);
    flag.resize(n+1);
    rep(i,n+1){
        dp[i].resize(n+1);
        flag[i].resize(n+1);
        rep(j,n+1){
            dp[i][j].resize(n+1);
            flag[i][j].resize(n+1);
        }
    }
    cout<<fixed<<setprecision(9)<<f(c[1],c[2],c[3])<<endl;
}