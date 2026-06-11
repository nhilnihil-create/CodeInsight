#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;

	vector<int> V = {105,135,165,189,195 };

	int ans = 0;

	for (int i = 0; i < 5; i++) {
		if (V[i] <= N)ans++;
	}

	cout << ans << endl;
}