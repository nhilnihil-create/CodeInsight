#include<bits/stdc++.h>
using namespace std;
int main() {
	int A, B;
	string s;
	cin >> A >> B >> s;
	bool ok = true;
	for (int i = 0; i < A + B + 1; i++)
	{
		if(i == A){
			if (s[i] != '-')
				ok = false;
		}
		else {
			if (s[i] < '0' || s[i] > '9')
				ok = false;
		}
	}

	if(ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
