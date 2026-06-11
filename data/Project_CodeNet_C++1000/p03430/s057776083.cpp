#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;

char str[308];
int n,K,Ans;
int f[305][305][305];

int main(){
	scanf("%s%d",str+1,&K); n=strlen(str+1);
	memset(f,0x80,sizeof(f));
	F(i,1,n) F(k,0,K) f[i][i][k]=1;
	F(i,2,n){
		if(str[i]==str[i-1]){
			F(k,0,K) f[i-1][i][k]=2;
		}
		else{
			f[i-1][i][0]=1;
			F(k,1,K) f[i-1][i][k]=2;
		}
	}
	F(Q,3,n){
		F(i,1,n-Q+1){
			int j=i+Q-1;
			f[i][j][0]=max(f[i+1][j][0],max(f[i][j-1][0],f[i+1][j-1][0]+2*(str[i]==str[j])));
			F(k,1,min(K,Q)){
				f[i][j][k]=max(f[i+1][j][k],max(f[i][j-1][k],f[i+1][j-1][k-(str[i]!=str[j])]+2)); 
			}
			F(k,min(K,Q)+1,K) f[i][j][k]=f[i][j][k-1];
		}
	}
	F(k,0,K) Ans=max(Ans,f[1][n][k]);
	printf("%d",Ans);
	return 0;
}