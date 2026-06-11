#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string S;
	cin >> S;

	int count = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '1') {
			count++;
		}
	}
	cout << count << endl;
}
