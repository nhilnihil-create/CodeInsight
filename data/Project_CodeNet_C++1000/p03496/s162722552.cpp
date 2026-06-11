#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<int> a(n);
	int max_a = -1, max_i = -1;
 	for(int i = 0; i < n; i++){
		cin >> a[i];
		max_a = max(abs(a[i]), max_a);
		if(max_a == abs(a[i])){
			max_i = i;
		}
	}
	vector<string> ans;
	ans.resize(2*n);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == a[max_i]) continue;
		a[i] += a[max_i];
		ans.push_back(to_string(max_i+1) + " " + to_string(i+1) + "\n");
		cnt++;
	}
	if(a[max_i] > 0){
		for(int i = 0; i < n-1; i++){
			if(a[i] <= a[i+1]) continue;
			a[i+1] += a[i];
			ans.push_back(to_string(i+1) + " " + to_string(i+2) + "\n");
			cnt++;
		}
	}else{
		for(int i = n-2; i >= 0; i--){
			if(a[i] <= a[i+1]) continue;
			a[i] += a[i+1];
			ans.push_back(to_string(i+2) + " " + to_string(i+1) + "\n");
			cnt++;
		}
	}
	cout << cnt << endl;
	for(auto x : ans){
		cout << x;
	}
	// for(int i = 0; i < n; i++){
	// 	cout << a[i] << " ";
	// }
	// cout << endl;
	return 0;
}