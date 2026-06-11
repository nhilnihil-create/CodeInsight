#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int x = 1;
	for (int i=0; i<n; i++){
		if (x<k) x = x+x;
		else x=x+k;
	}
	cout << x << endl;
}
