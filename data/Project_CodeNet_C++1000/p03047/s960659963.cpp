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

void sout(string* a, string* b) {
	if (*a > * b) {
		string c = *a;
		*a = *b;
		*b = c;
	}
}
int combination(int n, int k) {
	if (n > k && k > 0) {
		return (combination(n - 1, k) + combination(n - 1, k - 1));
	}
	else
		return 1;
}
int main() {
	int n, k;
	cin >> n >> k;
	cout << n - k + 1 << endl;
}