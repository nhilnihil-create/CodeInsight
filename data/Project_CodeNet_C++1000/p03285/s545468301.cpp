#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,t;
  cin >> N;
  int c = 0;
  for(int a = 0;a < 26;++a) {
  	for(int b = 0;b < 15;++b) {
      t = 4*a + 7*b;
      if(N == t) {
        ++c;
      }
    }
  }
  if(c >= 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
