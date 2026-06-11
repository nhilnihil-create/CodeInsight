#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;

	int red = 0;
	int blur = 0;
	for (int ii = 0; ii < N; ++ii){
		if (s[ii] == 'R'){
			red++;
		} else {
			blur++;
		}
	}


	if (red > blur){
		cout << "Yes" << "\n";
	} else {
		cout << "No" << "\n";		
	}

	return 0;
}
