#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)cin >> a[i];

	int cnt = 0;

	for(int i = 0; i < n;) {
		int j = i;
		while(a[j] == a[i] && j < n) {
			j++;
		}
		cnt += (j - i) / 2;
		i = j;
	}
	cout << cnt << endl;
}