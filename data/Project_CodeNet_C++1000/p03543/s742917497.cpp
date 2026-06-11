#include<iostream>
//#include<CastingInterop.h>
#include<string>
#include<array>
using namespace std;

int main()
{
	int x;
	string s;
	/*int arr1[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> arr1[i];
	}*/
	cin >> s;
	
	
	
	if (s[0] == s[1]&&s[0] == s[2] || s[1] == s[2] &&s[1]== s[3] || s[0] == s[1]&&s[1] == s[2]&&s[2] == s[3])
		cout << "Yes";
	else if (s[0] == s[1] || s[2] == s[3])
		cout << "No";

	else
		cout << "No";
}