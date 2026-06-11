#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,T;
	cin >> n >> T;
	int ans = 10000000;
	rep(i,n){
		int c,t;
		cin >> c >> t;
		if(t <= T) ans = min(c,ans);
	}
    if(ans == 10000000){
        cout << "TLE" << endl;
        return 0;
    }
	cout << ans << endl;
}