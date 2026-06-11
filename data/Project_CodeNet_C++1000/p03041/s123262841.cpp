#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    char s[n];
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=k;i<=n;i++)
    {
        s[i]=s[i]+32;
        break;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<s[i];
    }
}
