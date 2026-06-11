#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	string S;
	cin >> N >> K >> S;
	vector<int> A;
	int NowChar = 1;
	int now = 0;
	for (char c : S) {
		if (c == '0' + NowChar) now++;
		else {
			A.push_back(now);
			NowChar = 1 - NowChar;
			now = 1;
		}
	}
	A.push_back(now);
	int AN = A.size();
	now = 0;
	for (int i = 0; i < min(AN, 2 * K + 1); i++) now += A[i];
	int MAX = now;
	for (int i = 0; i + 2 * K + 1 < AN; i+=2) {
		now = now - A[i] - A[i + 1] + A[i + 2 * K + 1];
		if (i + 2 * K + 2 < AN) now += +A[i + 2 * K + 2];
		MAX = max(MAX, now);
	}
	cout << MAX << endl;

}
