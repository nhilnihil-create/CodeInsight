#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    unsigned long long sum=0,n;
    cin>>n;
    for(long long i=1;i<n/2&&(n-i)/i>i;i++)
    {
        //printf("1\n");
        if((n-i)%i==0) sum+=(n-i)/i;
    }
    cout<<sum<<endl;
    return 0;
}
