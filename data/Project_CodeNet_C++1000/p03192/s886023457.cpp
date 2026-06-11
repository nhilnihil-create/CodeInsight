#include <bits/stdc++.h>
using namespace std;

int main() {
	string n;
	cin >> n;
	int c = 0;
	for(int i = 0;i < 4;i++)
	{
		if(n.at(i) == '2')
		{
			c++;
		}
	}
	cout << c <<endl;
	return 0;
}
