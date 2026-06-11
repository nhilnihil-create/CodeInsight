#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back

int main()
{
	int n, m, x;
	cin >> n >> m >> x;
	int arr[n];
	memset(arr, 0, sizeof(arr));
	for(int i=0; i<m; i++) {
		int x;
		cin >> x;
		arr[x-1]++;
	}
	int cnt1 = 0, cnt2 = 0;
	for(int i=0; i<x; i++) {
		cnt1 += arr[i];
	}
	for(int i=x; i<n; i++) {
		cnt2 += arr[i];
	}
	cout << min(cnt1, cnt2) << endl;
	return 0;
}

