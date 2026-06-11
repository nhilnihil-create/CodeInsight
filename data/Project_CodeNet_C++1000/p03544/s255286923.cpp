#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a=2,b=1,n,ans=2;
    cin>>n;
    if(n==1)
        cout<<1;
    else
    {
        while(--n)
        {
            ans=a+b;
            a=b;
            b=ans;
        }
        cout<<ans;
    }
    return 0;
}

