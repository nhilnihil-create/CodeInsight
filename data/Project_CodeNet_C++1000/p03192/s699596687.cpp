#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, cnt;
int main() {
	cin >> n;
	while(n) {
		if(n%10==2) cnt++;
		n /= 10;
	}
	cout << cnt;
	return 0;
}
