#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
	int n, a, b;
	cin >> n >> a >> b;

	vector<int> ans(a, 1);

	int m = n-a;

	if(ans[0]+m < b){
		cout << -1 << endl;
		return 0;
	}else{
		for(int i = 0;i < ans.size()-1;i++){
			ans[i] += min(b-1, m);
			m -= min(m, b-1);
			if(m == 0) break;
		}

		if(ans[a-1]+m > b){
			cout << -1 << endl;
			return 0;
		}else{
			ans[a-1] += m;
		}
	}

	vector<int> an(n);

	int now = 0;
	int idx = 0;
	for(int i = 0;i < a;i++){
		now += ans[i];
		int tmp = now; 
		for(int j = 0;j < ans[i];j++){
			an[idx++] = tmp--;
		}
	}

	for(int i = 0;i < n;i++){
		cout << an[i];
		if(i < n-1){
			cout << " ";
		}else{
			cout << endl;
		}
	}

	return 0;
}
