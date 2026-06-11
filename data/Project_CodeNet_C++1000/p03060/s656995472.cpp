#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n;
cin>>n;
int a[n],b;
int ans=0;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
for(int i=0;i<n;i++)
{
cin>>b;
ans+=max(0,a[i]-b);
}
cout<<ans<<endl;
}