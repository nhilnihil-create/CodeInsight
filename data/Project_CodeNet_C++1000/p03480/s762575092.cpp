#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,j,k,l,m,n,ans=1e9,fin=0;

    string s;

    cin>>s;
    n = s.size();
    s = '*' + s;
    for(i=1;i<=n;i++)
    {
        if(s[i]!=s[i+1])
        {
            fin = max(i,n-i);
            ans = min(ans,fin);
        }
    }

    cout<<ans<<endl;
}
