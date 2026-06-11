#include<bits/stdc++.h>
using namespace std;
int main() {
	int N, T, A; cin >> N >> T >> A;
	int H[N];
	for(int i = 0; i < N; i++) cin >> H[i];
	int res = -1;
	double min = 1e9;
	for (int i = 0; i < N; i++)
	{
		double tmp = (double)(T - H[i] * 0.006);
		if(min > abs(A - tmp)) {
			min = abs(A - tmp);
			res = i+1;
		}
	}
	cout << res << endl;
	return 0;
}
