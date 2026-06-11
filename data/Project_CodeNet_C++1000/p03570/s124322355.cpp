#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[200010];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	std::ifstream in("in");
	std::cin.rdbuf(in.rdbuf());
#endif

	string s;
	cin >> s;
	int N = s.size();
	int bit = 0;
	map<int, int> m;
	m[0] = 0;
	for(int i = 0; i < N; i++){
		//cout << i << endl;
		dp[i + 1] = dp[i] + 1;
		int id = s[i] - 'a';
		// 全部余ってない
		int t = bit;
		if(m.count(t)){
			dp[i + 1] = min(dp[i + 1], m[t] + 1);
		}
		// idが余ってて他余ってない
		t = bit ^ (1 << id);
		if(m.count(t)){
			dp[i + 1] = min(dp[i + 1], m[t] + 1);
		}
		// idが余ってて他1つ余ってる
		for(int j = 0; j < 26; j++){
			if(j == id) continue;
			t = bit ^ (1 << id) ^ (1 << j);
			if(m.count(t)){
				//cout << char('a' + j) << endl;
				dp[i + 1] = min(dp[i + 1], m[t] + 1);
			}
		}

		if(!m.count(bit)){
			m[bit] = dp[i];
		}
		else{
			m[bit] = min(m[bit], dp[i]);
		}
		bit ^= 1 << id;
	}

	cout << dp[N] << endl;
}
