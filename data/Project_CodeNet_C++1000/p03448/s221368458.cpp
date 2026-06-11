#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int a, b, c, x;

int main(void){
	cin >> a >> b >> c >> x;
	int ans = 0;
	rep(i, a+1){
		rep(j, b+1){
			rep(k, c+1){
				if(500*i+100*j+50*k == x) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
