#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>

 
using namespace std;
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back

int N;
char S[304][304];
bool DP[304][304][304];//A,Bを選んだ時のA+C行目とA+B列目が一致しているかどうか
signed main(){
    scanf("%lld",&N);
    int ans=0;
    rep(i,N){
        char c;
        scanf("%c",&c);
        rep(j,N){
            scanf("%c",&S[i][j]);
            rep(k,N+1){
                DP[i][j][k]=true;
            }
        }
    }
    
    rep(a,N){
        rep(b,N){
            bool ifsym=true;
            if(a==0||b==0){
                rep(i,N){
                    rep(j,N-i){
                        if(S[(a+i)%N][(b+i+j)%N]!=S[(a+i+j)%N][(b+i)%N]){
                            DP[a][b][i]=false;
                            ifsym=false;
                        }
                    }
                }
            }else{
                rep(c,N){
                    if(!DP[a-1][b-1][c+1]||S[(a+N-1)%N][(b+c)%N]!=S[(a+c)%N][(b+N-1)%N]){
                        DP[a][b][c]=false;
                        ifsym=false;
                    }
                }
            }
            if(ifsym)ans++;
        }
    }
    printf("%lld\n",ans);
}


