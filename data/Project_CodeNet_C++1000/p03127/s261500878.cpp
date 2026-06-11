#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int a;
int ans;
cin>>ans;
for(int i=1;i<n;i++)
{
cin>>a;
ans=__gcd(ans,a);
}
cout<<ans<<endl;
return 0;
}

