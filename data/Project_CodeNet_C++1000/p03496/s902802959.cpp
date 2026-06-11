#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
typedef pair<int, int> P;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	int MAX = 0, idx = 0;
	rep(i, 0, n){
		cin >> a[i];
		if(abs(a[i]) > MAX){
			MAX = abs(a[i]);
			idx = i;
		}
	}
	vector<P> ans;
	rep(i, 0, n){
		ans.push_back({idx + 1, i + 1});
	}
	if(a[idx] >= 0){
		rep(i, 0, n - 1){
			ans.push_back({i + 1, i + 2});
		}
	}else{
		for(int i = n - 1; i >= 1; i--){
			ans.push_back({i + 1, i});
		}
	}
	cout << ans.size() << endl;
	for(int ii = 0; ii < ans.size(); ii++){
		cout << ans[ii].first << " " << ans[ii].second << endl;
	}
}