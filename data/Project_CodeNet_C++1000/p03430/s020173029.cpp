#include <bits/stdc++.h>

using namespace std;

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
char s[310];
int n,k,F[310][310][310];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	k=read();
	for(int i=1;i<=n;i++) F[i][i][0]=1;
	for(int i=1;i<n;i++)
	{
		F[i][i+1][0]=(s[i]==s[i+1])*2;
		F[i][i+1][1]=2;
	}
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l+i-1<=n;l++)
		{
			int r=l+i-1;
			for(int ks=0;ks<=k;ks++)
			{
				if(l>1) F[l-1][r][ks]=max(F[l-1][r][ks],F[l][r][ks]);
				if(l>1&&r<n) F[l-1][r+1][ks]=max(F[l-1][r+1][ks],F[l][r][ks]+(s[l-1]==s[r+1])*2);
				if(r<n) F[l][r+1][ks]=max(F[l][r+1][ks],F[l][r][ks]);
				if(l>1&&r<n) F[l-1][r+1][ks+1]=max(F[l-1][r+1][ks+1],F[l][r][ks]+2);
			}
		}
	}
	int Ans=0; for(int i=0;i<=k;i++) Ans=max(Ans,F[1][n][i]);
	cout << Ans << endl; return 0;
}
