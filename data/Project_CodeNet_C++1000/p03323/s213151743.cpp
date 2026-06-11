#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int a[26];
int main()
{	
	
	int a, b; cin >> a >> b;
	if (a == b || abs(a - b) == 1)
		cout << "Yay!";
	else
		cout << ":(";
}