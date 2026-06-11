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
	vector<vector<int>> c(3, vector<int>(3));
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cin >> c[i][j];
	}

	bool ok = false;

	for (int i = 0; i < 101;i++) {
		
			for (int k = 0; k < 101; k++){
				
					for (int m = 0; m < 101; m++){
						
							if (i + (c[1][1]-k) == c[0][1] && i + (c[2][2] - m) == c[0][2] && k + (c[0][0]-i) == c[1][0]
								&& k + (c[2][2]-m) == c[1][2] && m + (c[0][0] - i) == c[2][0] && m + (c[1][1] - k) == c[2][1]) {
								ok = true;
								break;
							}
						
					}
				
			}

		
	}

	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}