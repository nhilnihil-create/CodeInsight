// atc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include    <algorithm>
using namespace std;

int main()
{
	int x;
	cin >> x;

	int out=1,tmp;

	for (int i = 2;i<40; i++) {
		tmp = i;
		for (int j=0;; j++) {
			tmp = tmp*i;

			if (tmp == x) {
				out = tmp;
				break;
			}
			else if (tmp > x) {
				break;
			}

			if (tmp > out) {
				out = tmp;
			}

		}

	}
	cout << out;

	return 0;

}

