#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back

int main()
{	
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);
	int prev = 0;
	vector< int > v;
	for(int i=0; i<n; ) {
		int cnt = 0;
		prev = arr[i];
		if(arr[i]==prev)
		while(arr[i]==prev) {
			cnt++;
			i++;
			if(i==n) break;
		}
		else i++;
		v.pb(cnt);
	}
	sort(v.rbegin(), v.rend());
	int sz = v.size();
	ll sum = 0;
	for(int i=k; i<sz; i++) {
		sum += v[i];
	}
	cout << sum << endl;
	return 0;
}
