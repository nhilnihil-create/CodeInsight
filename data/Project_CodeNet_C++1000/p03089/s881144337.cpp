#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	list<int> B;
	bool HasAns = true;
	vector<int> Ans(N + 1);
	for (int i = 1; i <= N; i++) {
		int b;
		cin >> b;
		B.push_back(b);
	}
	for (int j = N; j >= 1; j--) {
		auto itr = B.end();
		HasAns = false;
		for (int i = B.size(); i >= 1; i--) {
			itr--;
			if (*itr == i) {
				Ans[j] = i;
				HasAns = true;
				B.erase(itr);
				break;
			}
		}
		if (!HasAns) break;
	}
	if (HasAns) for (int i = 1; i <= N; i++) cout << Ans[i] << endl;
	else cout << -1 << endl;
}