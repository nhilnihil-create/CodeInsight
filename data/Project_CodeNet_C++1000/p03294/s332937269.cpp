#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,a,sum=0;
  cin >> n;
  for(long i=0;i<n;i++) {
    cin >> a;
    sum+=a;
  }
  cout << sum-n << endl;
}