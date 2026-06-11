#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int red = count(s.cbegin(), s.cend(), '0');
	int blue = count(s.cbegin(), s.cend(), '1');

	cout << 2*min(red,blue) << endl;

	return 0;
}