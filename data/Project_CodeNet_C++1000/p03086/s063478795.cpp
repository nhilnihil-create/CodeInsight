#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include<math.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int ans = 0, sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
			sum++;
			if (sum > ans)ans = sum;
		}
		else sum = 0;
	}
	cout << ans << endl;
}