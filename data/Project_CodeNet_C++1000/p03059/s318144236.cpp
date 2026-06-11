#include<bits/stdc++.h>
using namespace std;

int main()
{
    int b,x,t,n=0,i;
    cin>>x>>b>>t;
    for(i=1;i*x<=(t+0.5);i++)
    {
        n=b*i;
    }
    cout<<n<<endl;
    return 0;
}