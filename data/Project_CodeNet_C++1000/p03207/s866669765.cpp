#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p,i,s=0,mx=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>p;
        s+=p;
        mx=max(mx,p);
    }
    cout<<s-(mx/2)<<endl;
}
