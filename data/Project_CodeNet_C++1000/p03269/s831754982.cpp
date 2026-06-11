#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int L,n;
int bitcount(int x)
{
    int res=0;
    for(int i=0;i<n;i++)  res+=((x>>i)&1);
    return res;
}
int main()
{
    cin>>L;  
    n=log2(L);
    n++;
    printf("%d %d\n",n,2*(n-1)+bitcount(L)-1);
    for(int i=1;i<n;i++)
    {
        printf("%d %d %d\n",i,i+1,(1<<(i-1)));
        printf("%d %d 0\n",i,i+1);
    }
    int sum=0;
    for(int i=n-1;i>=0;i--)
    {
        if((L>>i)&1)
        {
            if(i!=n-1)
            {
                printf("%d %d %d\n",i+1,n,sum);
            }
            sum+=(1<<i);
        }
    }
    return 0;
}