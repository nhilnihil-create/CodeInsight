#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,d,x;
cin>>n>>d>>x;
int arr[n];
for(int i=0; i<n; ++i)
cin>>arr[i];
long long int sum(n+x);
for(int i=0; i<n; ++i)
{
int cnt(0);
for(int j=1; j<1000; ++j)
{
if(j*arr[i]+1>d)
break;
++cnt;
}
sum+=cnt;
}
cout<<sum;
}