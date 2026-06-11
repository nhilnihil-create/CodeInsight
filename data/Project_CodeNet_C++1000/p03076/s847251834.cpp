#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int ans=0;
int k=0;
int a;
int mx=0;
for(int i=0;i<5;i++)
{
cin>>a;
ans+=a;
int h=a%10;
if(h==0)
{
h=10;
}
k+=10-h;
mx=max(mx,10-h);
}
cout<<ans+k-mx<<endl;
}