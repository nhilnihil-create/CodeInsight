#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	int A[101], x = 1e9, y = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
		x = min(x, A[i]);
		y = max(y, A[i]);
	}
	cout << y-x << endl;
}


