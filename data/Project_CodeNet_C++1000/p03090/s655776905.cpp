#include<iostream>
#include<array>
using namespace std;
int main() {
	
	/*int n;
	int b[101], c[101];
	cin >> n;
	int i,j,k;
	for (i = 1; i <= n; i++) {
		cin >> b[i];
	}
	int maxa, maxb;

	for (i = n; i >= 1; i--) {
		for (j = i; j >= 1; j--) {
			if (b[j] > j) {
				cout << -1;
				return 0;
			}
			else if (b[j] == j) {
				c[i] = j;
				for (k = j; k < n; k++) {
					b[k] = b[k + 1];
				}
				break;
			}
		}
	}
	for (i = 1; i <= n; i++) {
		cout << c[i];
		cout << '\n';
	}
	return 0;*/
	//B
	int n,m;
	cin >> n;
	int i, j;
	if (n % 2 == 0) {
		m = (n * (n - 1)) / 2 - n / 2;
		cout << m;
		cout << '\n';
		for (i = 1; i <= n; i++) {
			for (j = i + 1; j <= n; j++) {
				if ((i + j) == n + 1) {

				}
				else {
					cout << i;
					cout << ' ';
					cout << j;
					cout << '\n';
				}
			}
		}
	}
	else {
		//n%2 == 1;
		m = (n * (n - 1)) / 2 - (n-1) / 2;
		cout << m;
		cout << '\n';
		for (i = 1; i <= n-1; i++) {
			for (j = i + 1; j <= n-1; j++) {
				if ((i + j) == n) {

				}
				else {
					cout << i;
					cout << ' ';
					cout << j;
					cout << '\n';
				}
			}
			cout << i;
			cout << ' ';
			cout << n;
			cout << '\n';
		}
		
	}

	return 0;

}