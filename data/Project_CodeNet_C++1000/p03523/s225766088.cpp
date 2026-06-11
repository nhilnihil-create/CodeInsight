#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include<stack>
#include <unordered_map>

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}
int abs(int a) { return a < 0 ? -a : a; }

using namespace std;

int main() {
	string S;
	cin >> S;
	if (S.find("KIH") == string::npos) {
		cout << "NO";
		return 0;
	}
	int count = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'A') {
			S.erase(S.begin() + i);
			count++;
			if (count >= 2) {
				cout << "NO";
				return 0;
			}
          	i--;
		}
		else {
			count = 0;
		}
	}
	if (S == "KIHBR")
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
