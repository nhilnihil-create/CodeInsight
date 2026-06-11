#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int		N, A, B;
	cin >> N >> A >> B;
	cout << (B > A * N ? A * N : B) << endl;
}