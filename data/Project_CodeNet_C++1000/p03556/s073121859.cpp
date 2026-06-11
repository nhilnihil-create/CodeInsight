#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
int x;
cin>>x;int ans=0;
while(ans*ans<x)
{
ans++;
}
if(ans*ans!=x)
ans--;
cout<<ans*ans<<endl;
}