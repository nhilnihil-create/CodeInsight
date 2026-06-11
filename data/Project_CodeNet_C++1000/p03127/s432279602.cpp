#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b>a)
        swap(a,b);
    if(a%b==0)
        return b;
    //cout<<"1"<<endl;
    gcd(b,a%b);
}
int main()
{
    long long int a,b,c,d,n,t,r,i,j,k,x,y,m,p,s,mx,mn;
    cin>>t;
    int ar[t];
    for(i=0; i<t; i++)
    {
        cin>>ar[i];
    }
    b=ar[0];
    for(i=1; i<t; i++)
    {
        b=gcd(b,ar[i]);
        if(b==1)
            break;
    }
    cout<<b<<endl;
}

