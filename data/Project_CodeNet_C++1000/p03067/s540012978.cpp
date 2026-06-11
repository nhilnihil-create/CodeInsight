#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {

	int a, b, c;
	cin >> a >> b >> c;

	if (b < a)
		swap(b, a);

	if (a < c && c < b)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;

	return 0;
}