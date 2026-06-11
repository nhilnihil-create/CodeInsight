#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, odd = 0, even = 0,num;
	cin >> n;
	for (int i = 0;i < n; i++) {
		cin >> num;
		if (num % 2 == 0)even++;
		else odd++;
	}
	cout << (int)pow(3, n) - ((int)pow(2, even) * (int)pow(1, odd)) << endl;
}
