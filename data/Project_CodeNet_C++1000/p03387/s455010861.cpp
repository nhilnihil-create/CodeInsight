#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a(3);
  cin>>a[0]>>a[1]>>a[2];
  sort(a.rbegin(),a.rend());
  int sa=a[0]*2-a[1]-a[2];
  int kotae=sa/2;
  if (sa%2==1)kotae+=2;
  cout<<kotae<<endl;
  return 0;
}