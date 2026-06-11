#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back

int main()
{
	int n, x, d;
	cin >> n >> d >> x;
	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];
	int cnt=0;
	for(int i=1; i<=d; i++) {
		for(int j=0; j<n; j++) {
			if(i%arr[j]==1 || arr[j]==1) cnt++;
		}
	}
	cout << cnt + x << endl;
	return 0;
}

