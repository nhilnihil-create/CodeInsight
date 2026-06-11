#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,y;
	cin >> n >> y;
	rep(i,n+1)rep(j,n+1-i)rep(k,n+1-i){
		int sum = 0;
		sum = k*10000 + j*5000 + i*1000;
		if(sum == y && i+j+k == n){
			cout << k << " " << j << " " << i << endl;
			return 0;
		}
	}
	cout << -1 << " " << -1 << " " << -1 << endl;
}