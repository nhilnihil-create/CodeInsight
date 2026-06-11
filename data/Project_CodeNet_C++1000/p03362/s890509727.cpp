#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define _for(i,a,b) for(int i=a;i<=b;i++)
const int maxn = 55699;
int n,sum,prime[maxn],isprime[maxn],ans[maxn];
void ge()
{
    _for(i,2,maxn)
    {
        if(prime[i]==0)
        {
            isprime[++sum]=i;
            for(int j=i*2;j<=maxn;j+=i)prime[j]=1;
        }
    }
}
int main(int argc, char const *argv[])
{
    cin>>n;
    ge();
    int k = 0;
    _for(i,1,sum)
    {
        if(isprime[i]%5==1)
        {
            cout<<isprime[i]<<" ";
            k++;
        }
        if(k==n)
        {
            cout<<endl;
            return 0;
        }
    }
    return 0;
}