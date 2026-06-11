#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<cctype>
using namespace std;

void swapp(int *a, int *b) {
	if (*a > *b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}
int main() {
	int a[4];
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			swapp(&a[j], &a[j + 1]);
		}
	}
	if (a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}