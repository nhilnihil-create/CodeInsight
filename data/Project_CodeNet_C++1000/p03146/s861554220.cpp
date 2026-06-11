#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main(void) {
	int s;
	scanf("%d", &s);
	vector<int> a = {s};
	int m = 2;
	while (1) {
		if (s % 2 == 0) {
			s /= 2;
		} else {
			s = 3*s + 1;
		}
		// cout << m << " " << s << endl;
		for (int i = a.size(); i > 0; i--) {
			if (a[i - 1] == s) {
				printf("%d\n", m);
				return 0;
			}
		}
		a.push_back(s);
		m++;
	}
	return 0;
}
