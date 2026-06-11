#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>

using namespace std;


int main(){
	string s;
	cin >> s;

	int count = 0;

	for (int i = 0; i < s.length(); i++) {
		int count1=0;
		int l = i;
		while (s[l] == 'A' || s[l] == 'T' || s[l] == 'C' || s[l] == 'G') {
			count1++;
			l++;
		}
		if (count1 > count)count = count1;
	}

	cout << count << endl;

	return 0;
}
