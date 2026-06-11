#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(3));
	rep(i, n){
		int ai, bi;
		cin >> ai >> bi;
		a[i][0] = ai + bi;
		a[i][1] = ai;
		a[i][2] = bi;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	ll ta = 0;
	ll ao = 0;
	rep(i, n){
		if(i%2 == 0){
			ta += a[i][1];
		}else{
			ao += a[i][2];
		}
	}
	cout << ta - ao << endl;
	return 0;
}