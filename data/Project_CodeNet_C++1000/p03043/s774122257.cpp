#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin >> n >> k;
	double res = 0.0;
	for(int i=1; i<=n; i++){
		double prob = 1.0/n;
		int temp = i;
		while(temp<k){
			temp*=2;
			prob/=2;
		}
		res += prob;
	}
	cout << fixed << setprecision(10) << res;
	return 0;
}