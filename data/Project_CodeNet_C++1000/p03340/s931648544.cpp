#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long f[maxn],s[maxn];
long long ans;
int main()
{
    int n,x;
    cin>>n;
    f[0]=0,s[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        f[i]=f[i-1]+x;
        s[i]=s[i-1]^x;
    }
    int L=1;
    ans=0;
    for(int R=1;R<=n;R++)
    {
        while((f[R]-f[L-1])!=(s[R]^s[L-1])) L++;
        ans+=R-L+1;
    }
    cout<<ans<<"\n";
}
 