#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

int main() {
	string s;
	cin >> s;
	int A = s[0] - '0', B = s[1] - '0', C = s[2] - '0', D = s[3] - '0';
	int ans;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ans = A;
				if (i % 2 == 0) ans += B;
				else ans -= B;
				if (j % 2 == 0) ans += C;
				else ans -= C;
				if (k % 2 == 0) ans += D;
				else ans -= D;
				if (ans == 7) {
					if (i % 2 == 0) cout << A << "+" << B;
					else cout << A << "-" << B;
					if (j % 2 == 0) cout << "+" << C;
					else cout << "-" << C;
					if (k % 2 == 0) cout << "+" << D;
					else cout << "-" << D;
					cout << "=7" <<endl;
					return 0;
				}
			}
		}
	}
}