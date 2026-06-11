#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int n,count=0,i,h,sum=0,zum=0;
cin>>n;
long long int a[n],b[n];
for(i=0;i<n;i++)
{
    cin>>a[i];
}
for(i=0;i<n;i++)
{
    cin>>b[i];
}
for(i=0;i<n;i++)
{
    if(b[i]<a[i])
{
    sum=sum+a[i];
    zum=zum+b[i];
}
}
h=sum-zum;
cout<<h;
}
