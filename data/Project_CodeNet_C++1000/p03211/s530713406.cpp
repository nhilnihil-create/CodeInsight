#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	string S;
	cin >> S;

	int A = 999;

	int N = S.size();

	for (int i = 0; i <= N - 3; i++) {
		string Q = S.substr(i, 3);

		int num = atoi(Q.c_str());

		A = min(A, abs(num - 753));
	}

	cout << A << endl;
}