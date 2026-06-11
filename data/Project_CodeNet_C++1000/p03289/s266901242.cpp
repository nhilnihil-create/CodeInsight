#include "bits/stdc++.h"
using namespace std;


int main() {
	string S;
	cin >> S;
	if ('A' != S[0]) {
		cout << "WA"<<endl;
		return 0;
	}
	int count = 0; 
	for (int i = 2; i < S.size() - 1; ++i) {
		if ('C' == S[i]) {
			count++;
		}
	}
	for (int i = 1;i<S.size();++i) {
		if ('C' == S[i]) {
		}
		else {
			int num = S[i] - 'a';
			if (num >=0 && num <=25  ) {
			}
			else {
				cout << "WA" << endl;
				return 0;
			}
		}
	}
	if (1 == count) {
		cout << "AC" << endl;
	}
	else {
		cout << "WA" << endl;
	}
	return 0;
}