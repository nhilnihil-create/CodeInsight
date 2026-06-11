#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main(){
	IOS;
	int n, m;
	cin >> n >> m;
	int a[n], b[n], c[n];
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}

	
	int fans = 0, ans = 0;
	for(int x = 0; x < 9; x++){
		int sign[3];
		for(int k = 0; k < 3; k++){
			if( ((1<<k)&x) != 0 )
				sign[k] = -1;
			else
				sign[k] = 1;
		}

		for(int i = 0; i < n; i++){
			arr[i] = a[i]*sign[0] + b[i]*sign[1] + c[i]*sign[2];
		}

		sort(arr, arr+n);
		ans = 0;
		for(int i = 0, j = n-1; i < min(n, m); i++, j--){
			ans = ans + arr[j];
		}

		fans = max(fans, ans);
	}

	cout << fans << endl;
	return 0;
}