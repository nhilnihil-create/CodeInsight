#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace  std;

int main() {
	int max = 0;
	int num = 0;
	string S;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		num = 0;
		while (S[i] == 'A'|| S[i] == 'C'|| S[i] == 'G'|| S[i] == 'T') {
			num++;

			i++;
			if (num >= max)max = num;
		}
	}
	cout << max << endl;
	return 0;

}