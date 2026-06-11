#include <cstdio>
#include <iostream>
#include <set>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fi first
#define se second
using namespace std;
inline char nc()
{
    // return getchar();
    static char buf[100000],*l=buf,*r=buf;
    return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<class T> void read(T &x)
{
    x=0; int f=1,ch=nc();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
    while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
    x*=f;
}
typedef pair<int,int> pii;
const int maxn=2e5+50;
int n,a[maxn];
set<pii> s;
bool check(int c)
{
    s.clear();
    for(int i=2;i<=n;++i)
    {
        // debug("%d %d\n",c,i);
        if(a[i]<=a[i-1])
        {
            while(s.size()&&s.rbegin()->fi>a[i]) s.erase(*s.rbegin());
            int x=a[i];
            while(true)
            {
                set<pii>::iterator it=s.lower_bound(make_pair(x,0));
                int y=0; if(it!=s.end()&&it->fi==x) y=it->se,s.erase(it);
                if(++y==c)
                {
                    if(x==1) return 0;
                    --x; continue;
                }
                s.insert(make_pair(x,y));
                break;
            }
        }
    }
    return 1;
}
int main()
{
    read(n);
    for(int i=1;i<=n;++i) read(a[i]);
    int l=1,r=n,an=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1,an=mid;
        else l=mid+1;
    }
    printf("%d\n",an);
    return 0;
}