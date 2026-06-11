#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int>a(3);
  int n;
  cin>>a[0]>>a[1]>>a[2]>>n;
  sort(a.rbegin(),a.rend());
  while(n){
    a[0]*=2;
    n--;
  }
  int kotae=a[0]+a[1]+a[2];
  cout<<kotae<<endl;
  return 0;
}