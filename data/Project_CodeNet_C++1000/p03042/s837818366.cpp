#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	int l = n / 100;
	int r = n % 100;
	if (r == 0) {
		if (l == 0)cout << "NA" << endl;
		else if (l <= 12) cout << "MMYY" << endl;
		else cout << "NA" << endl;
	}
	else if (r <= 12) {
		if (l == 0)cout << "YYMM" << endl;
		else if (l <= 12) cout << "AMBIGUOUS" << endl;
		else cout << "YYMM" << endl;
	}
	else {
		if (l == 0)cout << "NA" << endl;
		else if (l <= 12)cout << "MMYY" << endl;
		else cout << "NA" << endl;
	}
}