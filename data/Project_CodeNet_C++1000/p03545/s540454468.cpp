#include "bits/stdc++.h"

using namespace std;

int main() {
	string S;
	cin >> S;
	vector<int>V(4);
	V[0] = S[0] - '0';	
	V[1] = S[1] - '0';	
	V[2] = S[2] - '0';
	V[3] = S[3] - '0';
	for (int i = 0;i<(1<<3);++i) {
		int n = V[0];
		string Sout;
		Sout += S[0];
		for (int j = 0;j<3;++j) {
			if (1 & (i>>j)) {
				n += V[j+1]; 
				Sout += "+";
			}
			else {
				n -= V[j + 1]; 
				Sout += "-";
			}
			Sout += S[j+1];
		}
		if (7 == n) {
			Sout += "=7";
			cout << Sout<<endl;
			return 0;
		}
	}
	return 0;
}
