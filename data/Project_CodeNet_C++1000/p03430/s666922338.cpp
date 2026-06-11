#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6+10;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl
#define Cerr(x) cerr<<(x)<<endl
#define fi first
#define se second

ll n,cnt,ans,a,b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos,K;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};
ll dp[305][305][305];//l～rでK回変更の最長

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>s>>K;
    rrrep(i,Size(s)-1,0){
        rrep(j,i,Size(s)){
            rep(k,K+1){
                if(i==j){
                    dp[i][j][k]=1;
                }
                else if(i+1==j){
                    if(s[i]==s[j]){
                        dp[i][j][k]=2;
                    }
                    else if(k>0){
                        dp[i][j][k]=2;
                    }
                    else{
                        dp[i][j][k]=1;
                    }
                }
                else{
                    dp[i][j][k]=max(dp[i+1][j][k],dp[i][j-1][k]);
                    if(s[i]==s[j]){
                        dp[i][j][k]=max(dp[i+1][j-1][k]+2,dp[i][j][k]);
                    }
                    if(k>0){
                        dp[i][j][k]=max(dp[i+1][j-1][k-1]+2,dp[i][j][k]);
                    }
                }
            }
        }
    }
    Cout(dp[0][Size(s)-1][K]);
    return 0;
}
