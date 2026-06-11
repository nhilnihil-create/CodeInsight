#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,t=0,r,c=0,a;
    cin>>n>>m;
    m=m+1;
    while(m>n)
    {
        a=n;

        while(n!=0)
        {
            r=n%10;
            t=r+t*10;
            n=n/10;
        }
        if(t==a)
        {
            c++;
            n=a+1;
            t=0;

        }
        else
        {

            n=a+1;
            t=0;

        }}
        cout<<c<<endl;
    }
