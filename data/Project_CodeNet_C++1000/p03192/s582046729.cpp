#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int counter = 0;

	string s = to_string(n);

	for(int i = 0; i < 4; ++i){
		if(s[i] == '2') ++counter;
		else continue;
	}

	cout << counter << "\n";

	return 0;
}