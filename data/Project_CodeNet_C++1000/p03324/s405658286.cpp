#include <bits/stdc++.h>
using namespace std;
int calc(int x) {
  int count = 0;
  while(x%100 == 0) {
	x /= 100;
	count++;
  }
  return count;
}
int main() {
	int d,n;
	cin >> d >> n;
	int count=0,t=0;
	while(count < n) {
      t++;
	  if(calc(t) == d) {
        count++;
      }
	}
	cout << t << endl;
	return 0;
}