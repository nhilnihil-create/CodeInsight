#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
ll ans1,ans2,ans;
const int sz=1e5+10;
char s[sz];
void solve()
{
    const ll n=strlen(s+1);
    ans1=ans2=n;
    for(ll i=1;i<=n;i++)
    {
        if(s[i]=='1')ans1=min(ans1,max(n-i,i-1));
        if(s[i]=='0')ans2=min(ans2,max(n-i,i-1));
    }
    ans=max(ans1,ans2);
}
main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    scanf("%s",s+1);
    solve();
    cout<<ans<<endl;
    return 0;
}