#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int l[n],r[n];
    l[0]=a[0];
    for(int i=1;i<n;i++)
    {
        l[i]=__gcd(a[i],l[i-1]);
    }
    r[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        r[i]=__gcd(a[i],r[i+1]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(i==0) ans=max(ans,__gcd(0,r[i+1]));
        else if(i==n-1) ans=max(ans,__gcd(l[i-1],0));
        else ans=max(ans,__gcd(l[i-1],r[i+1]));
    }
    cout<<ans;
    return 0;
}