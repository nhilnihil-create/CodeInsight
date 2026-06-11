#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int r,d,x,p;
    long long int n=10;
    cin>>r>>d>>x;
    while(n--)
    {
         p=(r*x)-d;
         cout<<p<<endl;
         x=p;
    }
}
