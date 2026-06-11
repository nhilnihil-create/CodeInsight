#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	int first,second;
	first = atoi(S.substr(0, 2).c_str());
	second = atoi(S.substr(2, 2).c_str());
	// cout << first << " " << second << endl;
	bool yymm = true;
	bool mmyy = true;
	if (first < 1 || 12 < first) {
		mmyy = false;
	}
	if (second < 1 || 12 < second) {
		yymm = false;
	}

	if (yymm && mmyy) {
		printf("AMBIGUOUS\n");
	} else if (yymm && !mmyy) {
		printf("YYMM\n");
	} else if (!yymm && mmyy) {
		printf("MMYY\n");
	} else {
		printf("NA\n");
	}

	return 0;
}
