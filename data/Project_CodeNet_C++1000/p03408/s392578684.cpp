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
typedef long long ll;

int main() {
	int N, M;
	cin >> N;
	vector<string> blue(N);
	for (int i = 0; i < N; i++) cin >> blue.at(i);
	cin >> M;
	vector<string> red(M);
	for (int i = 0; i < M; i++) cin >> red.at(i);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		string s = blue.at(i);
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (s == blue.at(j))cnt++;
		}
		for (int j = 0; j < M; j++) {
			if (s == red.at(j)) cnt--;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}