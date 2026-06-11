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
    int v[n],c[n],ans[n];
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++)
    {
        ans[i]=v[i]-c[i];
    }
    sort(ans,ans+n,greater<int>());
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(ans[i]<0) break;
        sum+=ans[i];
    }
    // if(sum==0) sum=ans[0];
    cout<<sum;
    return 0;
}