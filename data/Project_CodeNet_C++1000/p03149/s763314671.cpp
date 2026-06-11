#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	vector<int> N(4);
	rep(i,4)
		cin >> N.at(i);
	sort(N.begin(), N.end());

	if(N.at(0)==1 && N.at(1)==4 && N.at(2)==7 && N.at(3)==9)
		cout << "YES";
	else
		cout << "NO";
	cout << endl;
}