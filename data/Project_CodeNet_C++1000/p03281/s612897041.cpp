#include<iostream>
using namespace std;
#include <vector>
#define re(i,n) for(int i = 0; i < n; i++)

int main() {
	int n;
	int acnt = 0;
	cin >> n;
	int cnt = 0;

	for (int nn = 1; nn <= n; nn += 2) {
		cnt = 0;
		
		for (int i = 1; i <= nn; i++) {
			if (nn % i == 0)cnt++;
		}
		if (cnt == 8) acnt++;
	}
	cout << acnt << endl;
	return 0;
}