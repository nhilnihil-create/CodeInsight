#include<iostream>
using namespace std;
int n,a[2][101],sum[2][101];
void Solve(){
	for (int j=0;j<2;++j){
		for (int i=1;i<=n;++i){
			sum[j][i] = sum[j][i-1]+a[j][i]; 
		}
	}
	int mx = -1;
	for (int i=1;i<=n;++i){
		if (sum[0][i] + sum[1][n] - sum[1][i-1] > mx) mx = sum[0][i] + sum[1][n] - sum[1][i-1];
	}
	cout << mx;
}

void Input(){
	cin >> n;
	for (int i=1;i<=n;++i)
		cin >> a[0][i];
	for (int i=1;i<=n;++i)
		cin >> a[1][i];
}

signed main(){
	Input();
	Solve();
}
