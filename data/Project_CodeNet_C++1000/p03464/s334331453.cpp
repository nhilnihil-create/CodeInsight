#include<iostream>
using namespace std;
long long x=2,y=2;
int n,ans[100010];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>ans[i];
    }
    for(int i=n; i>=1; i--)
    {
        x=((x-1)/ans[i]+1)*ans[i];
        y=y/ans[i]*ans[i]+ans[i]-1;
    }
    if(x>y)
    {
        cout<<-1;
    }
    else
    {
        cout<<x<<" "<<y;
    }
    return 0;
}