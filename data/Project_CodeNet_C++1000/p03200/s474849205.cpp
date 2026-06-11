#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>s;
    n=s.size();
    int b[n];
    b[0]=0;
    if(s[0]=='B')
        b[0]+=1;
    
    else
        b[0]=0;
    for(int i=1;i<n;i++)
    {
        b[i]=b[i-1];
        if(s[i]=='B')
            b[i]+=1;
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='W') ans+=(i-1>=0?b[i-1]:0);
    }
    cout<<ans;
    return 0;
}