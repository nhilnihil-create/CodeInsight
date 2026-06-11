#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=5010;
int n,A,B,f[N],a[N];
main()
{
    n=in,A=in,B=in;
    forinc(i,1,n) a[i]=in;
    a[++n]=n;
    forinc(i,1,n)
    {
        f[i]=LLONG_MAX;
        int res=0;
        fordec(j,i-1,0)
        {
            if(a[j]>a[i]) ++res;
            else if(f[i]>f[j]+A*res+B*(i-j-1-res)) f[i]=f[j]+A*res+B*(i-j-1-res);
        }
    }
    cout<<f[n]<<"\n";
}
