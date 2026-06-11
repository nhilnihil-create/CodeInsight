#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,a,s=100;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> a;
    int k = 0;
    while (a%2==0) {
      a /= 2;
      k++;
    }
    if (k<s) {
      s = k;
    }
  }
  cout << s << endl;
}