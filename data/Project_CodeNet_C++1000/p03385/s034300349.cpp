#include<iostream>
#include<vector>
#include<string>
#include<cmath>


using namespace std;



int main() {
	string n;
	cin >> n;

	if (n!="abc"&&n!="acb"&&n!="bac"&&n != "bca"&&n != "cab"&&n != "cba") {
		cout << "No";
	}
	else
	{
		cout << "Yes";
	}
}