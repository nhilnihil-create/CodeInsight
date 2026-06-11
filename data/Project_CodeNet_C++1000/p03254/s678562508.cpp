#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back

int main()
{
	int n, s;
	cin >> n >> s;
	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);
	int cnt = 0;
	for(int i=0; i<n-1; i++) {
		s -= arr[i];
		if(s<0) break;
		cnt++;
	}
	if(s > 0 && s == arr[n-1]) cnt++;
	cout << cnt << endl;
	return 0;
}

