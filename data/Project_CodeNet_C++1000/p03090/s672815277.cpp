# include <bits/stdc++.h>
using namespace std;
vector < pair < int, int > > ans;
int n;
int main(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		for(int j = i + 1; j <= n; ++j){
			if((n % 2 == 1 && i + j != n) || (n % 2 == 0 && i + j != n + 1)){
				ans.push_back({i, j});
			}
		}
	}
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); ++i){
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
}
