# include<bits/stdc++.h>
using namespace std;
# define lowbit(x) ((x)&(-x))
# define pi acos(-1.0)
# define eps 1e-8
# define MOD 1000000007
# define INF 1000000000
# define mem(a,b) memset(a,b,sizeof(a))
# define FOR(i,a,n) for(register int i=a; i<=n; ++i)
# define FDR(i,a,n) for(register int i=a; i>=n; --i)
# define bug puts("H");
# define lch p<<1,l,mid
# define rch p<<1|1,mid+1,r
# define mp make_pair
# define pb push_back
typedef pair<int,int> PII;
typedef vector<int> VI;
# pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long LL;
inline LL Scan() {
    LL x=0;int f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
const int N=100005;
//Code begin....

int num[3];
char s[N];

int main ()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    FOR(i,1,len) ++num[s[i]-'a'];
    if (max(max(num[0],num[1]),num[2])-min(min(num[0],num[1]),num[2])<=1) puts("YES");
    else puts("NO");
    return 0;
}
