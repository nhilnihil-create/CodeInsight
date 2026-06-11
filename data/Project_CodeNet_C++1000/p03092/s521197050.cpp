#include<bits/stdc++.h>
#define ts cout<<"ok"<<endl
#define int long long
#define hh puts("")
#define pc putchar
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
using namespace std;
const int N=5005;
int n,A,B,a[N],pos[N],dp[N][N],s[N][N];
inline int read(){
    int ret=0,ff=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') ff=-1;ch=getchar();}
    while(isdigit(ch)){ret=ret*10+(ch^48);ch=getchar();}
    return ret*ff;
}
void write(int x){if(x<0){x=-x,pc('-');}if(x>9) write(x/10);pc(x%10+48);}
void writeln(int x){write(x),hh;}
void writesp(int x){write(x),pc(' ');}
signed main(){
	n=read(),A=read(),B=read();
	for(int i=1;i<=n;i++) a[i]=read(),pos[a[i]]=i;
	memset(dp,0x3f,sizeof(dp));
	memset(s,0x3f,sizeof(s));
	for(int i=0;i<=n;i++) s[0][i]=dp[0][i]=0;
	for(int i=1;i<=n;i++){//从小到大放 
		for(int j=0;j<=n;j++){
			if(pos[i]==j) dp[i][j]=min(dp[i][j],s[i-1][j-1]);
			dp[i][j]=min(dp[i][j],s[i-1][j]+(j<pos[i]?B:A));
		}
		s[i][0]=dp[i][0];
		for(int j=1;j<=n;j++) s[i][j]=min(s[i][j-1],dp[i][j]);
	}
	write(s[n][n]);
    return 0;
}