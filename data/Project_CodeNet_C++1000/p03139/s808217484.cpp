#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {

	int n, a, b;
	cin >> n >> a >> b;

	cout << min(a, b) << " ";

	a + b - n < 0 ? cout << 0 : cout << a + b - n;
	cout << endl;

	return 0;
}