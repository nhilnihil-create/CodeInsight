// Code for B - Algae
#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, d, x2000;
  cin >> r >> d >> x2000;

  int tmp = x2000;
  for (int i = 1; i <= 10; i++) {
    int next = tmp * r - d;
    cout << next << endl;
    tmp = next;
  }
	return 0;
}
