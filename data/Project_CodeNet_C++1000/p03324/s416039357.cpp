#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int d, n;
	cin >> d >> n;
	if(n == 100) n = 101;
	int ans = n*pow(100, d);
	cout << ans << endl;
	return 0;
}