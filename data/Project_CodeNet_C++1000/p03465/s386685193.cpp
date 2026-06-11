#include<bits/stdc++.h>
using namespace std;

const int N = 4e6 + 5;

bitset <N> dp;

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  	int n; cin >> n;
  	dp[0] = true;
  	int sum = 0;
  	while (n--){
      	int x; cin >> x; sum += x;
      	dp |= dp << x;
    }
  	sum = (sum + 1) / 2;
  	while (1){
		if (dp[sum]) return cout << sum, 0;
      	sum++;
    }
}