#include<bits/stdc++.h>
using namespace std;

int basket[200001];
int main()
{
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int a; cin >> a;
		basket[a]++;
	}
	sort(basket, basket+n+1);
	int c = 0;
	for (int i = n; i > n-k; --i) c += basket[i];
	cout << n-c << endl;
}

