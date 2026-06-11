#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a.at(i);
	sort(a.begin(), a.end(), greater<int>());
  
	int ret = 1;
	for (int i = 1; i < N; i++) {
      (a.at(i - 1) > a.at(i) ? ret++ : 0);
    }
  
	cout << ret << endl;
    return 0;
}
