#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int CountA, CountB, CountC;
int threshold;

int main() {

	string S;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'a') CountA++;
		if (S[i] == 'b') CountB++;
		if (S[i] == 'c') CountC++;
	}

	if (S.size() % 3 == 0) threshold = S.size() / 3;
	else threshold = S.size() / 3 + 1;

	if (CountA <= threshold && CountB <= threshold && CountC <= threshold)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}