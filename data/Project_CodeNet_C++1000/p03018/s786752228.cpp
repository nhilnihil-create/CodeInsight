/*Lower_Rating*/
/*Ex*/
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
using namespace std;

#define LL long long
#define DB double
#define MOD 1000000007
#define Pr pair<int,int>
#define X first
#define Y second
#define MAXN 1000000
#define eps 1e-10
#define INF 2147483647
#define mem(x,p) memset(x,p,sizeof(x))

LL read(){
  LL x=0,F=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
  return x*F;
}
int add(int a,int b){return (a+b>=MOD)?a+b-MOD:a+b;}
int dec(int a,int b){return (a-b<0)?a-b+MOD:a-b;}
int mul(LL a,int b){return a*b%MOD;}

int n,cntA;LL ans;
char s[MAXN+5];

int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='A')cntA++;
        else if(s[i]=='B'&&s[i+1]=='C')
        ans+=cntA,i=i+1;
        else cntA=0;
    }
    printf("%lld",ans);
}