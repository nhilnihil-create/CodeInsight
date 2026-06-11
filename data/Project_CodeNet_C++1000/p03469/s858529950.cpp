#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()

{
	string message;
	cin >> message;

	message.replace(2, 2, "18");

	cout << message << endl;

	return 0;
}
