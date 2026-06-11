#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
	//cout << "" << endl; // prints
	int N, K;
	vector<int> h;
	cin >> N >> K;
	for(int k = 0; k < N; k++){
		int temp = 0;
		cin >> temp;
		h.push_back(temp);
	}
	sort(h.begin(), h.end());
	int ans = 0;
	ans = h.at(K-1) - h.at(0);
	for(int i = 0; i <= N - K; i++){
		int temp = 0;
		temp = h.at(K-1+i) - h.at(i);
		ans = min(ans, temp);
	}

	cout << ans << endl;

	return 0;
}