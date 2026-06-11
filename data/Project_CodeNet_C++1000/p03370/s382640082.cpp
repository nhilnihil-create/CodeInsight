#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,x;
	cin >> n >> x;
	int sum = 0;
	int mo = 100000000;
	rep(i,n){
		int m;
		cin >> m;
		sum += m;
		mo = min(mo,m);
	}
	int ans = n + (x-sum)/mo;
	cout << ans << endl;
}