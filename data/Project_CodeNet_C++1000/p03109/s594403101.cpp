#include<iostream>
#include<stdio.h>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	int month = atoi(S.substr(5, 2).c_str());
	// cout << month << endl;
	printf(month <= 4 ? "Heisei\n" : "TBD\n");
	return 0;
}
