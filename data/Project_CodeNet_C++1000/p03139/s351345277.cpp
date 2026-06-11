#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int a,b;
cin>>a>>b;
int ans=a+b-n;
if(ans>0)
cout<<min(a,b)<<" "<<ans;
else cout<<min(a,b)<<" 0";
return 0;
}
