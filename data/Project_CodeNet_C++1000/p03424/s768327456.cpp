#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//#include <bits/stdc++.h>


int main() {
	int n,y;
	cin >> n;
	string s;
	
	y = 0;
	rep(i, n) {
		cin >> s;
		if (s == "Y") {
			printf("Four\n");
			break;
		}
		else {
			y++;
		}
	}
	if (y == n )
		printf("Three\n");
	return 0;
}
