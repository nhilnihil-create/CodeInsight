#include <bits/stdc++.h>
using namespace std;

int main(){
	int r, d, ini;
	cin >> r >> d >> ini;

	int i = 0;
	while (++i < 11) {
			ini = ini * r - d;
			cout << ini << endl;
	}
	return 0;
}
