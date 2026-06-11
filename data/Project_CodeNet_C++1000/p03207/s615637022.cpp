#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
	int N;
	int mx=0;
	int ans = 0;
	cin >> N;
	rep(i,N){int t; cin >> t; ans+=t; mx = max(mx,t);}
	ans = ans - mx/2;
	cout << ans << endl;

	return 0;
}