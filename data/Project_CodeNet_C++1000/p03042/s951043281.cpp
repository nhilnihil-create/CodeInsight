#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	int num0 = (S[0] - '0') * 10 + (S[1] - '0');
	int num1 = (S[2] - '0') * 10 + (S[3] - '0');
	bool case0 = false;
	bool case1 = false;
	if (num0>0 && num0 <= 12){
		case0 = true; 
	}
	if (num1 >0 &&num1 <= 12) {
		case1 = true;
	}
	if (case0 && case1) {
		cout << "AMBIGUOUS"<<endl;
	}
	else if (case0) {
		cout << "MMYY"<<endl;
	}
	else if (case1) {
		cout << "YYMM"<<endl;
	}
	else {
		cout << "NA" << endl;
	}
	return 0;
}