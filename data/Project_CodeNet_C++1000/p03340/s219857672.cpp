#include <bits/stdc++.h>

using namespace std;
const int N=5e5+5,mod=1e9+7;
#define ll long long
int a[N],nxt[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int lst=n;
    for(int i=n-1;i>=0;i--)
    {
        nxt[i]=lst;
        if(a[i]) lst=i;
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j=nxt[j])
        {
            if(sum&a[j]) break;
            sum^=a[j];
            ans+=nxt[j]-j;
        }
    }
    cout<<ans<<endl;
    return 0;
}
