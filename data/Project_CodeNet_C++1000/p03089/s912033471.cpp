#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin >> n;
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		cin >> b[i];
		b[i]--;
	}
	vector<int> ans;
	while(b.size() > 0){
		int z = -1;
		for(int i = 0; i < b.size(); i++){
			if(b[i] == i) z = i;
		}
		if(z == -1){
			cout << -1 << endl;
			exit(0);
		}
		ans.push_back(z);
		b.erase(b.begin() + z);
	}
	reverse(ans.begin(), ans.end());
	for(int x : ans){
		cout << x + 1 << '\n';
	}
}
