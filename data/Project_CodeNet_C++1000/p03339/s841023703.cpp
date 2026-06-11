#include<bits/stdc++.h>                          
using namespace std;
char s[300005];
int n,a[300005],b[300005],ans=1e6;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>s[i];
        if(s[i]=='W')a[i]=a[i-1]+1;
        else a[i]=a[i-1];
    }
    for(int i=n;i>=1;i--)
    {
        if(s[i]=='E')b[i]=b[i+1]+1;
        else b[i]=b[i+1];
    }
    for(int i=1;i<=n;i++)
	    ans=min(ans,a[i]+b[i]-1);
    cout<<ans<<endl;
    return 0;
}