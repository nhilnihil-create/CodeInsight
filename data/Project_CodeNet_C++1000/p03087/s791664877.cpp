#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N, Q;
	string S;
	cin >> N >> Q;
	cin >> S;
	vector<int> l(Q), r(Q);
	for (int i = 0; i < Q; i++)
		cin >> l[i] >> r[i];

	vector<int> v(N + 1);
	for (int i = 1; i < S.size(); i++) {
		int count = 0;
		if (S[i - 1] == 'A' && S[i] == 'C')
			count = 1;
		v[i + 1] = v[i] + count;
	}

	for (int i = 0; i < Q; i++) {
		cout << (v[r[i]] - v[l[i]]) << endl;
	}

	return 0;
}