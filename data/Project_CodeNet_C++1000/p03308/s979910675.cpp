#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	cout << a[n-1] - a[0];
	return 0;
}