#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,T;
	cin >> n >> T;
	int ans = 10000;

	for(int i=0; i<n; i++){
		int c,t;
		cin >> c >> t;
		if(t<=T) ans = min(ans,c);
	}

	if(ans!=10000) cout << ans << endl;
	else cout << "TLE" << endl;

	return 0;
}