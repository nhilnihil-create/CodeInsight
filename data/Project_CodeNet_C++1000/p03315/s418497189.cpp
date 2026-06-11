#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string S;
	cin >> S;

	int sol = 0;
	for (int ii = 0; ii < 4; ++ii){
		if (S[ii] == '+'){
			sol++;
		} else {
			sol--;
		}
	}

	cout << sol << endl;

	return 0;
}
