#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
int arr[100001];
int cnt[100001];
int main()
{	
	int n;
	cin >> n;
	ll ans = 0;
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
		if(arr[i]>n) {
			ans++;
			continue;
		}
		cnt[arr[i]]++;
	}
	for(int i=1; i<=n; i++) {
		if(cnt[i]!=i) {
			if(cnt[i] > i) {
				ans += cnt[i]-i;
			}
			else {
				ans += cnt[i];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
