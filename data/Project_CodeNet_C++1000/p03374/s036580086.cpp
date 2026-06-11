#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <stack>
#include <vector>
#define INF 0x3f3f3f3f
#define MOD 1000000009
# define FOR(i,a,n) for(register int i=a; i<=n; ++i)
# define FDR(i,a,n) for(register int i=a; i>=n; --i)
typedef long long ll;
typedef unsigned long long ull;

inline int scan() {
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
inline void Out(int a) {
    if(a<0) {putchar('-'); a=-a;}
    if(a>=10) Out(a/10);
    putchar(a%10+'0');
}
using namespace std;
struct A
{
    ll x;
    ll v;
};
int cmp(A a, A b)
{
    return a.x < b.x;
}
A a[100005];
ll sum[100005];
ll hou[100005];
ll maxs[100005];
ll maxs1[100005];
int main()
{
    ios::sync_with_stdio(false);
    ll n, c;
    cin >> n >> c;
    for(int i = 1; i <= n; i++)
    cin >> a[i].x >> a[i].v;
    sort(a+1, a+1+n, cmp);
    ll ans = 0;
    for(int i = 1; i <= n; i++)sum[i] = sum[i-1]+a[i].v;
    for(int i = n; i >= 1; i--)hou[i] = hou[i+1]+a[i].v;
    for(int i = n; i >= 1; i--)
    {
        maxs[i] = max(maxs[i+1], hou[i]-2*(c-a[i].x));
//        cout << maxs[i] << endl;
    }
    for(int i = 1; i <= n; i++)
    {
        maxs1[i] = max(maxs1[i-1], sum[i]-2*a[i].x);
    }
    for(int i = 1; i <= n; i++)
    {
//        cout << max(sum[i]-a[i].x+maxs[i+1], hou[i]-(c-a[i].x)) << ' ' << max(sum[i]-a[i].x, hou[i]-(c-a[i].x)+maxs1[i-1]) << endl;
        ans = max(ans, max(sum[i]-a[i].x+maxs[i+1], hou[i]-(c-a[i].x)));
        ans = max(ans, max(sum[i]-a[i].x, hou[i]-(c-a[i].x)+maxs1[i-1]));
    }
    cout << ans << endl;
    return 0;
}

