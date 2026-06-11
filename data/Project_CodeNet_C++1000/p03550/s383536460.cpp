#include <bits/stdc++.h>
using namespace std;
long a[2200];
int main(){
  long n,z,w,i;
  cin>>n>>z>>w;
  for(i=0;i<n;i++)cin>>a[i];
  if(n==1)cout<<labs(a[n-1]-w);
  else cout<<max(labs(a[n-1]-a[n-2]),labs(a[n-1]-w));
}