#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	const int n = s.size();
	vector<int> b(n + 1);
	for(int i = 0; i < n; ++i){
		const int c = s[i] - 'a';
		b[i + 1] = b[i] ^ (1 << c);
	}
	unordered_map<int, stack<int>> mp;
	for(int i = n; i >= 0; --i){ mp[b[i]].push(i); }
	vector<int> dp(n + 1, n);
	dp[0] = 0;
	for(int i = 0; i < n; ++i){
		mp[b[i]].pop();
		{
			const auto& st = mp[b[i]];
			if(!st.empty()){
				const int t = st.top();
				dp[t] = min(dp[t], dp[i] + (i == 0 ? 1 : 0));
			}
		}
		for(int c = 0; c < 26; ++c){
			const auto it = mp.find(b[i] ^ (1 << c));
			if(it == mp.end()){ continue; }
			const auto& st = it->second;
			if(!st.empty()){
				const int t = st.top();
				dp[t] = min(dp[t], dp[i] + 1);
			}
		}
	}
	cout << dp[n] << endl;
	return 0;
}

