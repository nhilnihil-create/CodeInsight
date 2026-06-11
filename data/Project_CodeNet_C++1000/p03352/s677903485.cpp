#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int x;
	cin >> x;
	int ans = 1;
	for(int i = 1; i < x; i++){
		int beki = 1;
		for(int j = 2; j < x; j++){
			beki = pow(i,j);
			if(beki > x) continue;
			ans = max(ans,beki);
		}
		if(beki > x) continue;
		ans = max(ans,beki);
	}
	cout << ans << endl;
}