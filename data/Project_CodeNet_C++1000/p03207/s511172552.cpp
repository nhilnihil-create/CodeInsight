#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> P;
	int total_p = 0;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		total_p += p;
		P.push_back(p);
	}

	sort(P.begin(), P.end());
	reverse(P.begin(), P.end());

	cout << total_p - P[0] / 2 << endl;
}


