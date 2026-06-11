#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	string S;
	cin >> S;

	int A = count(S.begin(), S.end(), 'a');
	int B = count(S.begin(), S.end(), 'b');
	int C = count(S.begin(), S.end(), 'c');

	if (A == B && B == C) cout << "Yes" << endl;
	else cout << "No" << endl;
}