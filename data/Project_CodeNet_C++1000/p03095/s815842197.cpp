#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cstring>
using namespace std;

const int MOD = 1000000007;

int main() {
	int N; cin >> N;
	string S; cin >> S;
	vector<int> x(26, 0);
	long long ans = 1;
	for (int i = 0; i < N; i++) {
		int y = S[i] - 'a';
		x[y]++;
	}
	for (int i = 0; i < 26; i++) {
		ans *= x[i] + 1;
		ans %= MOD;
	}
	cout << ans-1 << endl;
}



