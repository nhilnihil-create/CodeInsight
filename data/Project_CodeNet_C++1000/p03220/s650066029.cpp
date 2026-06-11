#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n, t, a;

int main(void){
	cin >> n >> t >> a;
	int ans;
	int val = INT_MAX;
	rep(i, n){
		int h;
		cin >> h;
		if(abs(1000*t-6*h-1000*a) < val){
			val = abs(1000*t-6*h-1000*a);
			ans = i+1;
		}
	}
	cout << ans << endl;
	return 0;
}
