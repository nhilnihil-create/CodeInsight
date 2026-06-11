#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000010
#define N 200010
char getc(){char c=getchar();while ((c<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9')) c=getchar();return c;}
int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int n;
char s[N];
signed main()
{
	int cnt=0;ll ans=0;
	scanf("%s",s+1);n=strlen(s+1);
	for (int i=1;i<=n;i++)
	if (s[i]=='A') cnt++;
	else if (s[i]=='B')
	{
		if (s[i+1]=='C') i++,ans+=cnt;
		else cnt=0;
	}
	else cnt=0;
	cout<<ans;
	return 0;
	//NOTICE LONG LONG!!!!!
}