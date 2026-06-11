#include<bits/stdc++.h>
using namespace std;

int main() {
  int a,b,ab,a_n,b_n;
  cin >> a >> b >> ab >> a_n >> b_n;
  int sum;
  for (int i=0; a_n-i>=0 || b_n-i>=0 ; i++) {
    if (i==0) {
      sum = a_n*a+b_n*b;
    }
    else {
      sum = min(sum, max(a_n-i,0)*a+max(b_n-i,0)*b + i*ab*2);
    }
  }
  cout << sum << endl;
}
