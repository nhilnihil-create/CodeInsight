#include<bits/stdc++.h>
#define fo(i,a,b) for(register int (i)=(a);(i)<=(b);++(i))
#define rd read()
#define maxn 200001
#define gc getchar()
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define pb push_back
#define db double
#define pu puts(" ")
using namespace std;
const int p=998244353;
int read()
{
	int x=0,f=1;
	char ch=gc;
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(isdigit(ch))x=x*10+ch-48,ch=gc;
	return x*f;
}
void print(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+48);
}
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=(ll)ans*a%p;
		a=(ll)a*a%p;
		b>>=1;
	}
	return ans;
}
char s[15];
int ans,ok=1;
int main()
{
    cin>>s;
    int l=strlen(s);
    fo(i,0,l-1)
    {
    	if(s[i]=='x')ans++;
	}
	if(ans>7)ok=0;
	puts(ok?"YES":"NO");
	return 0;
}