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
ll LLsqrt(ll x){
    ll L=0,R=1e9,mid,ans=-1;
    while (L<=R){
        mid=(L+R)>>1;
        if (mid*mid<=x)
            L=mid+1,ans=mid;
        else
            R=mid-1;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        ll a, b;
        cin >> a >> b;
        if(a == 1 && b == 1)
        {
            cout << 0 << endl;
            continue;
        }
        if(a > b)swap(a, b);
        ll sum = a*b-1;
        ll zong = LLsqrt(sum);
        ll ans = zong*2;
        if(sum/zong == zong)ans--;
        if(a != b)ans--;
        cout << ans << endl;
    }
    return 0;
}
