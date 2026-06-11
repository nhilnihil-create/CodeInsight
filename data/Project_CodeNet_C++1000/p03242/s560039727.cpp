#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
const int maxn=2222;
const ll modn=1e9+7;
const int inf=2e9+7;
const double PI = acos(-1.0);
const double eps=1e-8;
inline int lowbit(int x){return x&-x;}
inline ll lowbit(ll x) {return x&-x;}
inline int CountOneBinary(ll num){int ans=0;while(num){if(num&1) ans+=1;num>>=1;}return ans;}
inline void read(int &x){char c;x=0;for(c=getchar();c>'9'||c<'0';c=getchar());for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';}
inline void read(ll &x){char c;x=0;for(c=getchar();c>'9'||c<'0';c=getchar());for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';}
inline ll qpow(ll x,ll y){ll ans=1;while(y){if(y&1) ans=ans*x%modn;x=x*x%modn;y>>=1;}return ans;}
inline double qpow(double x,ll y){double ans=1;while(y){if(y&1) ans=ans*x;x=x*x;y>>=1;}return ans;}
int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
        for(int i=0;s[i];i++)
        {
            if(s[i]=='9') putchar('1');
            else putchar('9');
        }
        putchar('\n');
    }
}
