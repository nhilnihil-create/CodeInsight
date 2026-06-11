#include<bits/stdc++.h>
using namespace std ;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ans = 1000000001;
    for(int i=0;i+k-1<n;i++)
        {
            ans=min(ans,abs(a[i]-a[i+k-1]));
        }
    cout<<ans;
}
