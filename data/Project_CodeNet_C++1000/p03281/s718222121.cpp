#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N;
	cin >> N;

	int ans = 0;
	for (int n = 1; n <= N; ++n){
		if (n%2==0) continue;
		int cnt = 0;
	    for (ll ii = 1; ii*ii <= n; ++ii){
	        if (n % ii == 0){
	        	cnt++;
	            if (n / ii != ii){
	            	cnt++;
	            }
	        }
	    }
	    if (cnt == 8){
	    	ans++;
	    }
	}

	cout << ans << endl;

	return 0;
}
