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
	int N;
	cin >> N;
	double JPY = 0, BTC = 0;
	for (int i = 0; i < N; ++i)
	{
		string S;
		double money;
		cin >> money >> S;
		
		if (S == "JPY")
			JPY += money;
		else
			BTC += money;
	}
	cout << JPY + BTC * 380000 << endl;

	return;
}

int main() {

//	while (1)
		func();
	return 0;
}
