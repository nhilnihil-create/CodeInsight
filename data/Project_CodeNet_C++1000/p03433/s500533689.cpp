#include<iostream>
using namespace std;
int main() {
	int n, a;
	int ans;
	cin >> n >> a;
	ans = n % 500;
	if (a >= ans)
		cout << "Yes" << endl;
	if (a < ans)
		cout << "No" << endl;
}