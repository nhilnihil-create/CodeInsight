#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {

	bool a[10] = { false };

	for (int i = 0; i < 4; i++) {
		int tmp;
		cin >> tmp;
		a[tmp] = true;
	}

	if (a[1] && a[4] && a[7] && a[9])
		cout << "YES";
	else
		cout << "NO";
	cout << endl;

	return 0;
}