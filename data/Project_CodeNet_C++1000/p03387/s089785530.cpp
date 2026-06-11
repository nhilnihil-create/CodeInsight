#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
int a,b,c;
cin>>a>>b>>c;
int sum=a+b+c;
int Max=max({a,b,c});
int Min=min({a,b,c});
int mid=sum-Max-Min;
int ans=Max-mid;
Min+=ans;
if(((Max-Min)%2)==0)
ans+=(Max-Min)/2;
else
ans+=(Max-Min)/2+2;
cout<<ans<<endl;
return 0;
}
