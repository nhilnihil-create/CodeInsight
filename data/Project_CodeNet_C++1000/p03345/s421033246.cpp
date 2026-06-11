#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,k;
int main()
{
    scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
    if(k==0){printf("%lld\n",a-b);return 0;}
    k%=2;
    if(k==0) k=2;
    while(k--)
    {
        ll aa=b+c,bb=a+c,cc=a+b;
        a=aa;b=bb;c=cc;
    }
    printf("%lld\n",a-b);
}
