#include<iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	int iCount = 0;
	cin >> str;
	if (str[0] == '1') {
		iCount++;
	}
	if (str[1] == '1') {
		iCount++;
	}
	if (str[2] == '1') {
		iCount++;
	}

	cout <<  iCount;
	
	return 0;
}