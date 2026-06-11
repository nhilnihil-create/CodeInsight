#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
  
  	int ans = -1 * n;
  	for (int i = 0; i < n; i++) {
		int temp;
      	cin >> temp;
      	ans += temp;
    }
  	cout << ans;
}   