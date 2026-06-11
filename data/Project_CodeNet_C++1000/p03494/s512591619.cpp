#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back

int main()
{	
	int n;
	cin >> n;
	int arr[n];
	int m = INT_MAX;
	int cnt=0;
	for(int i=0; i<n; i++) {
		cnt = 0;
		cin >> arr[i];
		if(arr[i]%2) {
			cout << 0 << endl;
			return 0;
		}
		else {
			while(arr[i]%2==0) {
				arr[i]/=2;
				cnt++;
			}
			m = min(m, cnt);
		}
	}
	cout << m << endl;
	return 0;
}
