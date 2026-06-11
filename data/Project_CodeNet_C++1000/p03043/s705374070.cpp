#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;

	double ans = 0.0;
	for(int i=1; i<=n; i++){
		double p = 1.0/n;
		int x = i;

		while(0<x && x<k){
			x *= 2;
			p *= 0.5;
		}
		ans += p;
	}

	cout << fixed << setprecision(15) << ans << endl;
}