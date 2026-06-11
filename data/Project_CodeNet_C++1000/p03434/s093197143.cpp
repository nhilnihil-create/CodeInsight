#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a.at(i);
	sort(a.begin(), a.end(), greater<int>());
  
	int ret = 0;
	for (int i = 0; i < N; i++) ret += a.at(i) * (i % 2 ? -1 : 1);
	cout << ret << endl;

    return 0;
}
