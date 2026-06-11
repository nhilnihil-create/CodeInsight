#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int N;
	cin >> N;
	rep(i,N)
	{
		char c;
		cin >> c;
		if (c == 'Y')
		{
			cout << "Four" << endl;
			return 0;
		}
	}
	cout << "Three" << endl;
	return 0;
}