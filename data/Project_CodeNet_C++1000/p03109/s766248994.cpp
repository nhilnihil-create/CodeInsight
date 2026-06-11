#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;



void func()
{
	int year, month, day;
	string S, heisei;
	heisei = "2019/04/30";
	cin >> S;
	if (S > heisei)
		cout << "TBD\n";
	else
		cout << "Heisei\n";

	return;
}

int main() {

//	while (1)
		func();
	return 0;
}
