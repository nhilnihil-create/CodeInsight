#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	cout << S.substr(0, S.size() - 8) << "\n";
	return 0;
}
