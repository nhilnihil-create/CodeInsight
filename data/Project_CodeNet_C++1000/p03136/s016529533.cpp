#include<bits/stdc++.h>
using namespace std;

int d[33];
int main()
{
int n,s=0;
cin>>n;
int a[n+1];
for(int i=0;i<n;i++)cin>>a[i];
s=accumulate(a,a+n,0);
for(int i=0;i<n;i++)if(s-a[i]<=a[i])return 0&puts("No");
puts("Yes");

}

