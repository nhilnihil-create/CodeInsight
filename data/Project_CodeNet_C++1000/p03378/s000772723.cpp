#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,m,x;
	cin >> n >> m >> x;
	int to_zero = 0;
	int to_n = 0;
	rep(i,m){
		int a;
		cin >> a;
		if(a < x) to_zero++;
		else to_n++;
	}
	int ans = min(to_zero,to_n);
	cout << ans << endl;
}