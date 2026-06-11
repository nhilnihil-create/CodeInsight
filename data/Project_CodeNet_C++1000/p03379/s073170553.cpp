#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int>a(n),b(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    b[i]=a[i];
  }
  int chuo=n/2;
  sort(b.begin(),b.end());
  for(int i=0;i<n;i++){
    if(a[i] <b[chuo])cout<<b[chuo]<<endl;
    else cout<<b[chuo-1]<<endl;
  }
  return 0;
}
