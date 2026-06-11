#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

#include <climits>

using namespace std;

int main(){
	int n;
	cin >> n;

	bool flag = false;
	for(int i = 0; i <= (n / 4); i++) {
		for (int j = 0; j <= (n / 7); j++) {
			int total = 4 * i + 7 * j;
			if (total == n) {
				flag = true;
				break;
			}
		}

	}

	if(flag)cout << "Yes" << endl;
    else cout << "No" << endl;

	return 0;

}