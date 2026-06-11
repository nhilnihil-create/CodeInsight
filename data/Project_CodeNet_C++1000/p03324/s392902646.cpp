#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, n;
  cin>>d>>n;
  int res=n;
  if (res==100) res++;
  for (int i=0; i<d; i++) {
    res *= 100;
  }
  cout<<res<<endl;
  return 0;
}
