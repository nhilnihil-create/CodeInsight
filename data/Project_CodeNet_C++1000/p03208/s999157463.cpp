#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int N, K;
	cin >> N >> K;

	vector<int64_t> h(N);
	rep(i, N) cin >> h.at(i);
	int64_t minimum = INT64_MAX;
	sort(h.begin(), h.end());
	rep(i, N - K + 1){
		int64_t tmp = h.at(i + K - 1) - h.at(i);
		if (tmp < 0) tmp *= -1;
		minimum = min(minimum, tmp);
	}
	cout << minimum << endl;
}