#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	int a[n];
	long s = (long)pow(3,n);
	int b[n];
	int cnt = 0;
	rep(i, n)
	{ 
		cin >> a[i];
		if (a[i] % 2 == 0)
			cnt++;
	}
	int j,k,l;
	int i = 1;

	printf("%ld",s - (long)pow(2, cnt));
	return (0);
}
