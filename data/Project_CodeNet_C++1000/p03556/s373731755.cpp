#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    for(long long i=n;i>=1;i--)
    {
        double d=sqrt(i);
        if(d-floor(d)==0)
        {
            cout<<i<<"\n";
            break;
        }
    }
    
    return 0;
}