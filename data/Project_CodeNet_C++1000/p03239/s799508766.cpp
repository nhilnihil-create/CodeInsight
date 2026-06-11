#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int main()
{
int n,t;
cin>>n>>t;
int a,b;
int mn=100000;
for(int i=0;i<n;i++)
{
cin>>a>>b;
if(b<=t)
{
mn=min(a,mn);
}
}
if(mn==100000)
{
cout<<"TLE";
}
else
{
cout<<mn<<endl;
}
}
