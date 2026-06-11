#include <cstdio>
#include <bitset>

int n,a,s;
std::bitset<2002005> b;

int main()
{
    for(b[0]=1,scanf("%d",&n);n--;)
        scanf("%d",&a),b|=b<<a,s+=a;
    for(int i=(s+1)>>1;true;++i)if(b[i])return printf("%d\n",i),0;
}