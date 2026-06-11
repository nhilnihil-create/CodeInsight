#include<bits/stdc++.h>
using namespace std;

int main() {
	char x,y;
	cin >> x >> y;

	if(x > y)
		cout << ">" << endl;
	if(x < y)
		cout << "<" << endl;
	if(x == y)
		cout << "=" << endl;
}