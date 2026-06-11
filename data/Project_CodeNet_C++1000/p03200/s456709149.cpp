#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	string S;
	cin >> S;
	long long ans = 0; 
	int Bcount = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'B') {
			Bcount++;
		}
		else{
			ans += Bcount;
		}
	}
	cout << ans << endl;
	}
