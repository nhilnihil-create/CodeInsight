//W4P3R
#include<bits/stdc++.h>
#define inf 1e9
#define eps 1e-6
#define re register int 
#define FOR(i,a,b) for(re i=a;i<=b;i++)
#define REP(i,a,b) for(re i=a;i>=b;i--)
#define mp make_pair
#define pb push_back
#define pf push_front
#define pa pair<int,int>
#define fr first
#define sd second
#define Z(x) (x>=mod?x-mod:x)
#define lowbit(x) (x&(-x))
#define N 100010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
    char ch=getchar();
    ll s=0,w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
    return s*w;
}
char s[N];
int p[N],n;
int tot=1;
void Solve(int rt,int sz,int up)
{
	if(sz==0)return ;
	REP(i,up,2)
	{
		if(p[i])
		{
			++tot;int x=tot;
			cout<<rt<<" "<<x<<endl;
			Solve(x,i-1,i-1);sz-=i;break;
		}
	}
	while(sz--){cout<<rt<<" "<<++tot<<endl;}
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%s",s+1);n=strlen(s+1);
    FOR(i,1,n)p[i]=s[i]-'0';
    if(!p[1]||p[n]){puts("-1");return 0;}
    FOR(i,1,n-1){if(p[i]&&!p[n-i]){puts("-1");return 0;}}
    Solve(1,n-1,n/2);
    return 0;
}