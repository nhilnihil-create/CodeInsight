#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>
#include <regex>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}


int main() {
	int ans = 0;
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	for (int r = 0; r*R <= N; r++) {
		for (int g = 0; r * R + g * G <= N; g++) {
			int rest = N - r * R - g * G;
			if (rest >= 0 && rest % B == 0) ans++;
		}
	}
	print(ans);
}