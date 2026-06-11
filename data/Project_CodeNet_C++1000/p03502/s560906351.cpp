#include "bits/stdc++.h"
using namespace std;

int main() {
	int n,h;
	h = 0;
	cin >> n;
	int n_cn = n;
	for (int i = 0; i < 8; i++)
	{
		h += n_cn % 10;
		n_cn /= 10;
	}
	
	if (!(n % h)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}