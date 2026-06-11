#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int a,b,k;
cin>>a>>b>>k;
set<int> st;
for(int i=1;i<=a;i++)
{
if(a%i==0)
{
st.insert(i);
}
}
int ans=0;
for(int i=b;i>=1;i--)
{
if(b%i==0 && st.count(i))
{
k--;
if(k==0)
{
ans=i;
}
}
}
cout<<ans<<endl;
}