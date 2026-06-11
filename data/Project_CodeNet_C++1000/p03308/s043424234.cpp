#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	int ans = 0;
	rep(i,n) cin >> a[i];
	for(int i = 0;i < n-1;i++){
		for(int j = i+1;j < n;j++){
			ans = max(ans,abs(a[i]-a[j]));
		}
	}
	cout << ans << endl;
}