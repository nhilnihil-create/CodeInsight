#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int A, B;
	cin >> A >> B;
	int rec = 0;
	for (int i = A; i <= B; i++) {
		string S = to_string(i);
		if (S[0] != S[4] || S[1] != S[3]) {
			rec++;
		}
	}
	cout <<  B - A - rec + 1 << endl;
	return 0;
}