#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 550
#define INF 1000000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000000;
const int MOD = 1000000007;
ll dp[MAX][4];
int main(){
    string s;
    cin>>s;
    char c[3]={'A','B','C'};
    dp[0][0]=1;
    REP(i,SZ(s)){
        REP(j,4){
            if(s[i]=='?'){
                dp[i+1][j]+=3*dp[i][j];
                dp[i+1][j]%=MOD;
                if(j!=3){
                    dp[i+1][j+1]+=dp[i][j];
                    dp[i+1][j+1]%=MOD;
                }
            }else if(j<3&&s[i]==c[j]){
                dp[i+1][j+1]+=dp[i][j];
                dp[i+1][j+1]%=MOD;
                dp[i+1][j]+=dp[i][j];
                dp[i+1][j]%=MOD;
            }else{
                dp[i+1][j]+=dp[i][j];
                dp[i+1][j]%=MOD;
            }
        }
    }
    OUT(dp[SZ(s)][3]);
    return 0;
}