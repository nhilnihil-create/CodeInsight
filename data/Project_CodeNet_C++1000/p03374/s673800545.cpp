#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	long long c,i,n,l = 0,r = 0,a = 0,ans = 0,x[100010],v[100010];
	cin >> n >> c;
	x[0] = 0; x[n+1] = c;
	for(i=1;i<=n;i++){
		cin >> x[i] >> v[i];
		l += v[i];
	}
	ans = l-2*x[n];
	for(i=n;i>=1;i--){
		l -= v[i];
		r += v[i];
		a = max(a,r-c+x[i]);
		ans = max(ans,a+l-2*x[i-1]);
	}
	
	a = 0;
	ans = max(ans,r-2*(c-x[1]));
	for(i=1;i<=n;i++){
		r -= v[i];
		l += v[i];
		a = max(a,l-x[i]);
		ans = max(ans,a+r-2*(c-x[i+1]));
	}
	cout << ans << endl;
}