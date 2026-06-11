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
	int N;
	cin >> N;

	for (int i = 0; i < S.length(); i++) {
		if (i == 0) {
			cout << S[i];
		}else if(i % N == 0) {
			cout << S[i];
		}
	}
	cout << endl;

	
}
