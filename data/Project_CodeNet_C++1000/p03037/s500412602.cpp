#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,l,r,mx=-1,mn=2000000,i,a=0;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>l>>r;
        mx=max(mx,l);
        mn=min(mn,r);
    }
    cout<<(mn<mx?a:mn-mx+1)<<endl;
}
