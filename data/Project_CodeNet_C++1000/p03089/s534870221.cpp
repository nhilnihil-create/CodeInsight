#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> b(n);
	vector<int> ans(n);
	rep(i, n){
		cin >> b.at(i);
	}
	
	for(int i = n-1; i >= 0; i--){
		int index, max = -1;
		for(int j = 0, k = 1; j < n; j++){
			if(b.at(j) == -1) continue;
			if(b.at(j) == k){
				index = j;
				max = k;
			}
			k++;
		}
		if(max != -1){
			ans.at(i) = max;
			b.at(index) = -1;
		}else{
			cout << -1 << endl;
			return 0;
		}
	}
	
	rep(i, n) cout << ans.at(i) << endl;
	
	return 0;
}