#include <bits/stdc++.h>
using namespace std;

int calc(int x) {
	int ret = 0;
	while(x % 100 == 0) {
		x /= 100;
		++ret;
	}
	return ret;
}
int main() {
  int d, n;
  cin >> d >> n;
  int val = 0, cnt = 0;
  while (cnt < n){
    val++;
    if (calc(val) == d) cnt++;
  }
  cout << val << endl;
}