#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[10],max=0,sum=0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (max < a[i])
			max = a[i];
		sum += a[i];
	}
	if (sum - max > max)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}