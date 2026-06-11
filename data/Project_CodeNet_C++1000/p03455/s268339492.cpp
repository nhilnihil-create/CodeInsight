

#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
#define PI acos(-1)

int main()
{
	int a, b;
	cin >> a >> b;

	int c = a * b;

	if (c % 2) {
		cout << "Odd";
	}
	else {
		cout << "Even";
	}
	

}

