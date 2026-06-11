#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void write(ll x)
{
    char F[200];
    int tmp = x > 0 ? x : -x;
    if (x < 0)
        putchar('-');
    int cnt = 0;
    while (tmp > 0) {
        F[cnt++] = tmp % 10 + '0';
        tmp /= 10;
    }
    while (cnt > 0)
        putchar(F[--cnt]);
}
inline ll read()
{
    ll x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return x;
}
int sum,a[200010];
ll n, p, q, t,l;
void Imsuperman()
{
    cin>>n;
    ll ans=0;
    for(int i=0;i<n;i++){
        a[i]=read();
        while((sum^a[i])!=sum+a[i]) sum^=a[l++];
        ans+=i-l+1;
        sum^=a[i];
    }
    cout<<ans<<endl;
}
int main()
{
    Imsuperman();
    return 0;
}
