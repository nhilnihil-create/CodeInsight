#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, y;
	cin >> n >> y;
	int res1 = -1, res2 = -1, res3 = -1;
	for(int i=0; i<=n; i++){
		for(int j=0; i+j<=n; j++){
			int k=n-i-j;
			int total = 10000*i+5000*j+1000*k;
			if(total==y){
				res1 = i;
				res2 = j;
				res3 = k;
			}
		}
	}
	cout << res1 << " " << res2 << " " << res3 << endl;
}
