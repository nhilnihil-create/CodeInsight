#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int n, d, x;

int main(void){
	cin >> n >> d >> x;
	vector<int> a(n);
	int ans = 0;
	rep(i, n){
		int a;
		cin >> a;
		ans += (d-1)/a+1;
	}
	cout << ans+x << endl;
	return 0;
}
