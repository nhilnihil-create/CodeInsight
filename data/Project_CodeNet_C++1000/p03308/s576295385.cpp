#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> A;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}

	int maxNum = *max_element(A.begin(), A.end());
	int minNum = *min_element(A.begin(), A.end());

	cout << abs(maxNum - minNum) << endl;

}