#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)




int main(){
	int n,t;
	cin >> n >> t;
	int ans = 100000;
	rep(i,n){
		int a,b;
		cin >> a >> b;
		if (b <= t){
			ans = min(ans,a);
		}
	}
	if (ans == 100000) cout << "TLE" << endl;
	else cout << ans << endl;
	
	
	return 0; 
}

