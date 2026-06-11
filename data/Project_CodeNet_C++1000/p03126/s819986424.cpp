#include<bits/stdc++.h>
using namespace std;
int main() {
	int N, M; cin >> N >> M;
	vector<int> A(M, 0);
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int a; cin >> a; a--;
			A[a]++;
		}
	}

	int res = 0;
	for (int i = 0; i < M; i++)
	{
		if(A[i] == N) res++;
	}

	cout << res << endl;
	return 0;
}
