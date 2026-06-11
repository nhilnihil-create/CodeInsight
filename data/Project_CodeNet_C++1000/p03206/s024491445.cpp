/**
 *    author:  yoseph
 *    created: 18.07.2020 22:14:04      
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string pt = "Christmas";
	int d;
	cin >> d;
	for (int i = 0; i < 25 - d; ++i)
		pt = pt + " Eve";
	cout << pt << "\n";
	return 0;
}
