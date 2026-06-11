#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long int n,i,k,kotae=0;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++){
    cin>>a[i];
    a[i]-=i+1;
  }
  sort(a,a+n);
  k=a[n/2];
  for(i=0;i<n;i++){
    kotae+=abs(a[i]-k);
  }
  cout<<kotae;
}
