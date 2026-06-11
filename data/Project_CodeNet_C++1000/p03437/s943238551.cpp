#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	unsigned int a, b;
	cin >> a >> b;
	if (a == b)cout << -1 << endl;
	else if (a < b)cout << a << endl;
	else if (a % b == 0)cout << -1 << endl;
	else cout << a << endl;
	return 0;
}