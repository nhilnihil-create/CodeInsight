#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> a(n);
	rep(i, n) cin >> a[i];

	int sm = 0;
	rep(i, n) sm += a[i];

	int mn = INT_MAX / 10;
	int mi = -1;
	rep(i, n){
		int val = abs(a[i] * n - sm);
		if(val < mn){
			mn = val;
			mi = i;
		}
	}

	cout << mi << endl;
}
