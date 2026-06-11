#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a);i<(b);++i)


int main() {
	string S;
	cin >> S;
	string T = { "AKIHABARA" };
	int j = 0;
	int i;
	int Anum = 0;
	for (i = 0;  j < T.length();) {
		if (i < S.length() && S[i] == T[j]) {
			j++;
			i++;
			continue;
		}
		if (T[j] == 'A') {
			j++;
			Anum++;
			continue;
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	if (j == T.length() && S.length() + Anum == T.length()) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}