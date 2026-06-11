#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	int N, T;
	cin >> N >> T;

	vector<int> C;

	for (int i = 0; i < N; i++) {
		int c, t;
		cin >> c >> t;

		if (t > T)continue;

		C.push_back(c);
	}

	sort(C.begin(), C.end());

	if (C.size() == 0)cout << "TLE" << endl;
	else cout << C[0] << endl;


}