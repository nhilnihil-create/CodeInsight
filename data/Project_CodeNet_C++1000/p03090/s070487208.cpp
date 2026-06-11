#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

signed main(){
	int n;
	scanf("%d", &n);
	if(n % 2 == 1){
		cout << (n - 1) * (n - 1) / 2 << endl;
		for(int i = 1; i < n; i++){
			for(int j = i + 1; j <= n; j++){
				if(i + j != n){
					cout << i << " " << j << endl;
				}
			}
		}
	}
	else{
		cout << n * (n - 2) / 2 << endl;
		for(int i = 1; i < n; i++){
			for(int j = i + 1; j <= n; j++){
				if(i + j != n + 1) cout << i << " " << j << endl; 
			}
		}
	}
}