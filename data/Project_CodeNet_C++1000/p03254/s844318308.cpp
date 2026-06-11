#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N, x;
	cin >> N >> x;
	vector<int> a(N);
	rep(i,N) cin >> a[i];
	sort(a.begin(),a.end());
	int ans = 0;
	rep(i,N) {
		x -= a[i];
		if(x<0){
			cout << ans << endl;
			return 0;
		}
		if(i == N-1&& x > 0){
			cout << ans << endl;
			return 0;
		}
		if(x==0){
			ans++;
			cout << ans << endl;
			return 0;
		}
		ans++;
	}
	

}











