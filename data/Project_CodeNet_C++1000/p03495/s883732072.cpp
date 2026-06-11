
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
	int N, K; cin >> N >> K;
	vector<int> A(N, 0);
	for (int i = 0; i < N; ++i) {
		int n; cin >> n; --n;
		++A[n];
	}
	int kind = 0;
	for (int i = 0; i < N;++i) {
		if (A[i]) {
			++kind;
		}
	}
	int del = kind - K;
	int sum = 0;
	int delCnt = 0;
	sort(A.begin(), A.end());
	for (int i = 0; delCnt < del; ++i) {
		if (A[i]) {
			sum += A[i];
			++delCnt;
		}
	}
	cout << sum << endl;
}
