#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,sum=0; cin >> a >> b;
  int D = b - a;
  for(int i =1; i<=D; i++) {
    sum +=i;
  }
  cout << sum - b << endl;
}