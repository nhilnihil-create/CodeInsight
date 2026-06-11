#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)
typedef long long ll;

using namespace std;

int main(void) {
	int N; cin >> N;
	vector<int> L(N);
	int sum = 0;
	int longest = 0;
	rep(i, N) {
		cin >> L[i];
		sum += L[i];
		if (L[i] > L[longest])longest = i;
	}

	cout << (L[longest] < sum - L[longest] ? "Yes" : "No") << endl;

	return 0;
}