#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k,l,r;
    string s;
    cin>>n>>k;
    cin>>s;
    vector<long long> pre(n+1);
    for(int i=1;i<n;i++)
    {
        if(s[i-1]=='A' && s[i]=='C')
        {
            pre[i]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i]+pre[i-1];
    }
    while(k--)
    {
        cin>>l>>r;
     if(l==r) cout<<0<<endl;
     else
       {
           r--;
         cout<<pre[r]-pre[l-1]<<endl;
       }

    }
    return 0;


}
