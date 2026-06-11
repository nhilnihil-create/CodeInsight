#include<iostream>
using namespace std;
int main() {


	//B
	int bin[21];
	int i;
	bin[0] = 1;
	for (i = 1; i < 21; i++) {
		bin[i] = bin[i - 1] * 2;
	}
	int l;
	cin >> l;
	int n, m;
	int a[60], b[60], c[60];
	for (i = 20; i >= 0; i--) {
		if (bin[i] <= l) {
			n = i;
			break;
		}
	}
	for (i = 0; i < n; i++) {
		a[2 * i] = i + 1;
		b[2 * i] = i + 2;
		c[2 * i] = 0;
		a[2 * i + 1] = i + 1;
		b[2 * i + 1] = i + 2;
		c[2 * i + 1] = bin[n - i - 1];
	}
	m = 2 * n;
	int sum = bin[n];
	l = l - sum;
	int n2;
	while (l > 0) {
		for (i = 20; i >= 0; i--) {
			if (bin[i] <= l) {
				n2 = i;
				break;
			}
		}
		a[m] = 1;
		b[m] = n + 1 - n2;
		c[m] = sum;
		m++;
		sum = sum + bin[n2];
		l = l - bin[n2];
	}
	
	cout << n+1 << ' ' << m << endl;
	for (i = 0; i < m; i++) {
		cout << a[i] << ' ' << b[i] << ' ' << c[i] << endl;
	}
	return 0;

	//A

	/*long long int n, k,a,b;
	cin >> n >> k;
	a = ((long long int)(n / k)) ;
	b = ((long long int)(2 * n / k)) - ((long long int)(n / k));
	if (k % 2 == 1) {
		cout << a * a * a << endl;
	}
	else {
		cout << a * a * a + b * b * b<< endl;
	}
	return 0;
	*/

}