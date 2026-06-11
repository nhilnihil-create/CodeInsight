#include<bits/stdc++.h>
using namespace std;
int i,j,a[10],n,b,c,l,k;
int main()
{
  for(cin>>n;i<n;i++)cin>>a[i];
  sort(a,a+n,greater<int>());
  c+=a[0]/2;
  for(i=1;i<n;i++)c+=a[i];
  cout<<c;
}