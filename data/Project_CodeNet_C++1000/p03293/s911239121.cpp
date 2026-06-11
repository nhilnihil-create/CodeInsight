#include<iostream>
#include<cmath>
#include<iomanip>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<limits>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	s1 = s1 + s1;
	int sz = s2.size();
	for( int i=0;i<sz;i++)
		if (s1.compare(i,sz, s2) == 0) {
			cout << "Yes";
			return 0;
		}
	cout << "No";
	return 0;
}