#include<bits/stdc++.h>
using namespace std;

int main()
{
	string x, y; cin >> x >> y;
	sort(x.begin(), x.end());
	sort(y.begin(), y.end() , greater<char>());
	if (x < y)
		cout << "Yes";
	else cout << "No";
}

// 