#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, b, p = 0, q = 0;
  cin >> N;
  int a[N];
  
  for (int i = 0; i < N; i++) {
	cin >> b;
    a[i] = b;  
  }

  while (q == 0) {
    for (int i = 0; i < N; i++) {
      if (a[i] % 2 == 1) q = 1;
      a[i] /= 2;
    }
  	p++;
  }
  cout << p - 1 << endl;
}
