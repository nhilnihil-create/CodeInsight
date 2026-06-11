#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,k;
  cin>>n>>k;
  vector<long long>a(n);
  for(long long i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end());
  long long wa=0;
  for(long long i=0;i<k-1;i++){
    wa+=a[i+1]-a[i];
  }
  long long kotae=wa;
  for(int i=1;i<n-k+1;i++){
    wa=wa-(a[i]-a[i-1])+(a[i+k-1]-a[i+k-2]);
    //cout<<wa<<" ";
    kotae=min(kotae,wa);
  }
  cout<<kotae<<endl;
  return 0;
}
