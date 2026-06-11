#include <bits/stdc++.h>
using namespace std;
int main()
{
long long a,b,sum=1;
cin>>a>>b;
if(a>=b)
{
    if(a%b==0)
        {
        sum=a+b;
    cout<<sum;
    }
    else
        {
    sum=a-b;
    cout<<sum;
    }}
    else
    {
        if(b%a==0)
            {
            sum=a+b;
            cout<<sum;
            }
            else
                {
            sum=b-a;
            cout<<sum;
            }
    }

}

