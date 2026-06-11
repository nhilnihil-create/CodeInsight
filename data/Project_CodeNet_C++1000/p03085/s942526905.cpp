#include<iostream>
#include<string>
using namespace std;

int main() {

	string S;
	cin >> S;

	string before = "ATCG";
	string after = "TAGC";

	char ans = 'A';

	for (int i = 0; i < before.size(); i++)
	{
		if (S[0] == before[i]) ans = after[i];
	}
    
	cout << ans << endl;
}

