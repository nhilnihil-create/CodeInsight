#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,A,B;
	cin >> N >> A >> B;
	vector<int> a(N);
	rep(i,N)cin >> a[i];
	int ans;
	if(N==1)ans = abs(a[0]-B);
	else {
		ans = abs(B-a[N-1]);
		ans = max(ans,abs(a[N-2]-a[N-1]));
	}
	cout << ans << endl;
}