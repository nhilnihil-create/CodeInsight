#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int func(int n)
{
    int sum=0;
    while(n)
        sum+=n%10,n/=10;
    return sum;
}

int main()
{
    int n;
    int a,b;
    cin>>n;
    cin>>a>>b;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        if(func(i)>=a&&func(i)<=b)
            sum+=i;
    }
    cout<<sum<<endl;
}
