#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int a[26];
int b[26];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    str s;cin>>s;

    for(int i=0;i<n;i++)a[s[i]-'a']++;

    int ans=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<26;j++)b[j]=0;

        for(int j=0;j<i;j++)b[s[j]-'a']++;

        int num=0;

        for(int j=0;j<26;j++)num+=(b[j]>0&&a[j]-b[j]>0?1:0);

        ans=max(ans,num);
    }
    
    cout<<ans<<"\n";

    return 0;
}
