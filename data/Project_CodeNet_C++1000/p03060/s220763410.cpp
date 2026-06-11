#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >>n;
  vector<int>a(n),b(n),sa(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>b[i];
  }
  for(int i=0;i<n;i++){
    sa[i]=a[i]-b[i];
  }
  sort(sa.rbegin(),sa.rend());
  int sum=0;
  for(int i=0;i<n;i++){
    if(sa[i]<0)break;
    sum+=sa[i];
  }
  cout<<sum<<endl;
  return 0;
}
  
