#include<bits/stdc++.h>
using namespace std;


int main()
{
	string s; cin >> s;
	regex r ("A[a-z][a-z]*C[a-z]*[a-z]");
	cout << (regex_match(s,r) ? "AC" : "WA") << endl;
}

