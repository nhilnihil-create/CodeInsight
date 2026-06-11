#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n;
bitset<N*N>b;
int main()
{
    b.set(0,1);
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        sum+=x;
        b|=b<<x;
    }
    for(int i=sum/2+sum%2;;i++)
        if(b[i])
    {
        printf("%d\n",i);
        return 0;
    }
}
