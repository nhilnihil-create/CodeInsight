#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> mochi(N);

	for (int i = 0; i < N; i++) {
		cin >> mochi.at(i);
	}

	sort(mochi.begin(), mochi.end());
    mochi.erase(unique(mochi.begin(), mochi.end()), mochi.end());

	int Out = mochi.size();
	cout << Out;
}