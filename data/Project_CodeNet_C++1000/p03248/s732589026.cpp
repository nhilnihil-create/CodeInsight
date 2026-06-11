#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
const int maxn=1e5+7;
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
char s[maxn];
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int n=strlen(s);
        bool flag=0;
        if(s[n-1]=='1'||s[0]=='0')
        {
            puts("-1");
            continue;
        }
        for(int i=0;i<n-1;i++)
        {
            int j=n-2-i;
            if(s[i]!=s[j])
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            puts("-1");
            continue;
        }
        int from=1,to=2;
        for(int i=0;i<n-1;i++,to++)
        {
            printf("%d %d\n",from,to);
            if(s[i]=='1') from=to;
        }
    }
}
