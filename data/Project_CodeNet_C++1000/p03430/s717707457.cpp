//wls niubi!
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL mod = 1e9 + 7;
inline int read()
{
	int x = 0,f = 1;char ch = getchar();
	for(;!isdigit(ch);ch = getchar())if(ch == '-')f = -f;
	for(;isdigit(ch);ch = getchar())x = 10 * x + ch - '0';
	return x * f;
}
int n,K;
char ch[310];
int f[310][310][310];
int main()
{
	scanf("%s",ch + 1);n = strlen(ch + 1);K = read();
	for(int i=1;i<=n;i++)for(int j=0;j<=K;j++)f[i][i][j] = 1;
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i+l-1<=n;i++)
		{
			int j = i + l - 1;
			for(int k=0;k<=K;k++)
			{
			    f[i][j][k] = max(f[i + 1][j][k],f[i][j - 1][k]);
			    if(ch[i] == ch[j])f[i][j][k] = max(f[i][j][k],f[i + 1][j - 1][k] + 2);
			    if(k)f[i][j][k] = max(f[i][j][k],f[i + 1][j - 1][k - 1] + 2);
			}
		}
	}
	int ans = 0;
	cout<<f[1][n][K];
}