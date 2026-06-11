#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	string S;
	cin >> S;

	vector<int> ABS;
	for (int i = 0; i < S.length() - 2; i++) {
		string sub = S.substr(i, 3);
		int abssub = abs(753 - stoi(sub));
		ABS.push_back(abssub);
	}

	sort(ABS.begin(), ABS.end());

	cout << ABS[0] << endl;
	
}



