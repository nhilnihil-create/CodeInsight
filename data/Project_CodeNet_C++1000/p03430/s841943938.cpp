#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
    int x = 0; char ch = gc(); bool positive = 1;
    for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}
const int N=305;
int dp[N][N][N],n,m;
char s[N];
int main(){
    scanf("%s",s+1); m=read(); n=strlen(s+1);
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=n+1;i++){
        memset(dp[i][i],0,sizeof(dp[i][i]));
        if(i)memset(dp[i][i-1],0,sizeof(dp[i][i-1]));
    }
    for(int o=2;o<=n;o++)
        for(int i=1;i<=n;i++){
            int j=i+o-1;
            if (j>n)
                break;
            for(int k=0;k<=m;k++){
                if (k)
                    dp[i][j][k]=dp[i+1][j-1][k-1];
                if (s[i]==s[j])
                    dp[i][j][k]=min(dp[i][j][k],dp[i+1][j-1][k]);
                dp[i][j][k]=min(dp[i][j][k],dp[i+1][j][k]+1);
                dp[i][j][k]=min(dp[i][j][k],dp[i][j-1][k]+1);
            }
        }
    cout<<n-dp[1][n][m]<<endl;
}