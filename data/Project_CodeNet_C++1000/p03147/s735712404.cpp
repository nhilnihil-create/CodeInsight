#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>


using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }

int N;

bool mizu(vector<int>& hs) {
	int l=0, r;
	for (l = 0; l < N; l++) {
		if (hs[l] != 0)break;
	}
	if (l == N)return false;

	for (int i=l; i < N; i++) {
		if (hs[i] != 0)hs[i]--;
		else break;
	}
	return true;
}
int main() {
	cin >> N;
	vector<int> hs(N);
	for (auto& h : hs) cin >> h;

	int count = 0;
	while (mizu(hs)) {
		count++;
	}
	print(count);
}