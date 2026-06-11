#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,x,m,minm=1000000;
  cin >> n >> x;
  for(long i=0;i<n;i++) {
    cin >> m;
    minm=min(minm,m);
    x-=m;
  }
  cout << n+x/minm << endl;
}