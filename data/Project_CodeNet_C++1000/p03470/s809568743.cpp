#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	cin >> n;
	int a[n]; 
	map <int, int> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		m[a[i]] = 1;
	}
	cout << m.size() << endl;
}

