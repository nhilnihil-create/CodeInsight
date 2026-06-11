#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;
	vector<int> LeftBlack(N + 1,0);
	int white = 0;
	for (int i = 1; i <= N; i++) {
		if (S[i-1]=='#') LeftBlack[i] = LeftBlack[i - 1] + 1;
		else {
			LeftBlack[i] = LeftBlack[i - 1];
			white++;
		}
	}
	int MIN = N;
	for (int i = 0; i <= N; i++) MIN = min(MIN, LeftBlack[i] + white - (i - LeftBlack[i]));
	cout << MIN << endl;
}