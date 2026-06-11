#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	string S;
	cin >> S;
	int count = 10000;
	vector<int> a(S.length());
	for (int i = 0; i < S.length(); i++) {
		a[i] = S[i] - '0';
	}
	for (int i = 0; i < S.length() - 2; i++) {
		count = min(count,abs(753 - (a[i]*100+a[i+1]*10+a[i+2])));
	}
	cout << count << endl;
	return 0;
}