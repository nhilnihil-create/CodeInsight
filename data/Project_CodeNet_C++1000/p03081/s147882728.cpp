#include <bits/stdc++.h>
using namespace std;

int n,q,ans = 0;
char t[200010],d[200010];
string s;

bool C(int x){
	for(int i = 0;i < q;i++){
		if(s[x] == t[i]){
			x += (d[i] == 'L') ? -1 : 1;
		}
		if(x < 0) return true;
		if(x >= n) return false;
	}
	return false;
}

signed main(){
	cin >> n >> q >> s;
	for(int i = 0;i < q;i++){
		cin >> t[i] >> d[i];
	}
	for(int a = 0;a < 2;a++){
		int low = -1,up = n;
		while(up - low > 1){
			int mid = (up + low) / 2;
			if(C(mid)) low = mid;
			else up = mid;
		}
		ans += low + 1;
		reverse(s.begin(),s.end());
		for(int i = 0;i < q;i++){
			d[i] = ((d[i] == 'L') ? 'R' : 'L');
		}
	}
	cout << n - ans << endl;
}
