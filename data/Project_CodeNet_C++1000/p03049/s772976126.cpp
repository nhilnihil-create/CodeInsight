#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int A = 0, B = 0, AB = 0, BA = 0;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		A += (s.back() == 'A' && s.front() != 'B');
		B += (s.back() != 'A' && s.front() == 'B');
		BA += (s.back() == 'A' && s.front() == 'B');
		for (int j = 0; j < s.length() - 1; j++) AB += (s.substr(j, 2) == "AB");
	}
	while (BA > 0 && A != B) {
		(A < B ? A : B)++;
		BA--;
	}
	if (A == 0 && B == 0) BA--;
	cout << AB + min(A, B) + max(0, BA) << endl;
}