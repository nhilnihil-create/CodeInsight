#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, T, A;
	cin >> N >> T >> A;

	vector<double>V;
	for (int i = 0; i < N; i++) {
		int H;
		cin >> H;

		double Temp = T - H * 0.006;

		V.push_back(Temp);
	}

	int ans = 0;

	for (int i = 0; i < V.size(); i++) {
		if (abs(V[i] - A) < abs(V[ans] - A)) {
			ans = i;
		}
	}

	cout << ans + 1 << endl;
}