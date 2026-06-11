#include<iostream> 
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, k,m=1,r=0,i;

	cin >> n >> k;
	if (n == 1) {
		if (2 > k + 1)
			cout << k + 1 << endl;
		else
			cout << 2 << endl;
		return 0;
	}
	while (m < k ) {
		m *= 2;
		r++;
	}
	for (i=0;i < n-r;i++) {
		m += k;
	}
	cout << m << endl;
	return 0;
}