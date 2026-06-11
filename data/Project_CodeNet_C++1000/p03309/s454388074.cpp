#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,i,j;cin>>n;int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++)  a[i]-=(i+1);
    sort(a,a+n);
    ll s=0;
    for(i=0;i<n;i++) s+=abs(a[i]-a[n/2]);
    cout<<s;


    return 0;
}
