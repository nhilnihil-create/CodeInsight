#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(int i=(x);i<=(y);++i)
#define try(i,x,y) for(int i=(x);i>=(y);--i)
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=305;

int n,m;
char s[MAXN];
int f[MAXN][MAXN][MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
	#endif
	scanf("%s",s+1);readint(m);n=strlen(s+1);
	enum(i,1,n)
		enum(k,0,m)
			f[i][i][k]=1;
	enum(len,2,n)
		enum(i,1,n-len+1)
		{
			int j=i+len-1;
			enum(k,0,m)
			{
				f[i][j][k]=max(f[i+1][j][k],f[i][j-1][k]);
				if(s[i]==s[j])chkmax(f[i][j][k],f[i+1][j-1][k]+2);
				if(k)chkmax(f[i][j][k],f[i+1][j-1][k-1]+2);
			}
		}
	printf("%d\n",f[1][n][m]);
    return 0;
}