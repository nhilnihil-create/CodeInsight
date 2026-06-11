#include<bits/stdc++.h>

using namespace std;

int main() {

	string S;
	cin >> S;

	
	int a = S.size();
	for (int i = 0; i < 2; i++){
      int cou=0;

		for (int j = 0; j < S.size(); j++)
		{
			if (j % 2 == 0 && S[j] != (char)(i + '0')) cou++;
			if (j % 2 == 1 && S[j] == (char)(i + '0')) cou++;
		}

		a = min(a, cou);
	}

	cout << a << endl;
}

