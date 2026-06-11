#include<bits/stdc++.h>
using namespace std;
 
int main(void){

	int n;
	cin >> n;
	
	vector<int> v(n);
	vector<int> c(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++) cin >> c[i];
	
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		if(v[i] > c[i]){
			ans += v[i] - c[i];
		}
	}
	
	cout << ans;
	return 0;
}