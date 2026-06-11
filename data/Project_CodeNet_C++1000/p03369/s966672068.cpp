
#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int cost = 700;
	string s;
	cin >> s;

	if (s[0]=='o') {
		cost = cost + 100;
	}

	if (s[1] == 'o') {
		cost = cost + 100;
	}

	if (s[2] == 'o') {
		cost = cost + 100;
	}

	cout << cost << endl;

	return 0;
	
}