#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {

	int a[3], b[3], dob[4] = {}, num = 0;

	for (int k = 0; k < 3; k++) {
		cin >> a[k] >> b[k];
		a[k]--;
		b[k]--;
		for (int l = 0; l < 4; l++) {
			if (a[k] == l)dob[l]++;
			if (b[k] == l)dob[l]++;
		}
	}

	for (int l = 0; l < 4; l++) {
		if (dob[l] == 2)num++;
	}

	if (num>=2)cout << "YES\n";
	else cout << "NO\n";



	return 0;
}