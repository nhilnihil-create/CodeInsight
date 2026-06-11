#include<iostream>
using namespace std;
int main() {
	int n, k;
	int sum = 1;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		if (sum + k <= sum * 2) sum +=k;
		else sum *=2;
	}
	cout << sum;
}
