#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
ll gcd(ll a,ll b)
{
    if(b!=0) return gcd(b,a%b);
    else return a;
}
ll n;
int main()
{
    scanf("%lld",&n);
    printf("%lld\n",2*n/gcd(2,n));
}
