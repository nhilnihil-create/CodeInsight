#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int> card(n);
	for (int i = 0; i < n; i++) cin >> card.at(i);
	sort(card.begin(), card.end(), greater<int>());

	int sumA = 0, sumB = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) sumA += card.at(i);
		else sumB += card.at(i);
	}
	cout << sumA - sumB << endl;
}