#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N, X;
	cin >> N >> X;

	int total = 0;
	vector<int> M;
	for (int i = 0; i < N; i++) {
		int m;
		cin >> m;
		total += m;
		M.push_back(m);
	}

	sort(M.begin(), M.end());

	int minSize = M[0];

	int n = (X - total) / minSize;

	cout << N + n << endl;
}


