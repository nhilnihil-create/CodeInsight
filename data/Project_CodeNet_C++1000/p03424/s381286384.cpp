#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
 
int main() {
	int n;
	string s;
	int flg = 0;
	cin >> n;

	rep(i, n)
	{
		cin >> s;
		if (s == "Y")
		{
			flg = 1;
			break;
		}
	}
	if (flg == 0)
	{
		cout << "Three" << endl;
	}
	else
	{
		cout << "Four" << endl;
	}
}