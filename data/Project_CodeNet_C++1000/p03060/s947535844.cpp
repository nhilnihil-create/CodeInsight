#include <iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> V;
	vector<int> C;
	for (int i = 0; i < N; i++) {
		int v;
		cin >> v;
		V.push_back(v);
	}

	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;
		C.push_back(c);
	}


	int total = 0;
	for (int i = 0; i < N; i++) {
		if (V[i] > C[i]) {
			total += (V[i] - C[i]);
		}
	}

	cout << total << endl;

}


