#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<float> X;
	vector<string> U;
	for (int i = 0; i < N; i++) {
		float x;
		string u;
		cin >> x >> u;
		X.push_back(x);
		U.push_back(u);
	}

	float total_yen = 0.0;
	for (int i = 0; i < N; i++) {
		if (U[i] == "JPY") {
			total_yen = total_yen + X[i];
		}
		else if (U[i] == "BTC") {
			total_yen = total_yen + X[i]* 380000.0;
		}
	}

	cout << total_yen << endl;

}
