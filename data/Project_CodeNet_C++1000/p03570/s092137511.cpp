//DP, map<26bit, sorted_vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

string s;
unordered_map<int, vector<int> > poses;
int keys[200001];

void setPoses() {
	int cnt[26] = {0};
	int i, j;
	
	for (i = 0; i <= s.length(); i++) {
		int key = 0;
		for (j = 0; j < 26; j++) {
			if (cnt[j]) {
				key += (1 << j);
			}
		}
		
		if (poses.find(key) == poses.end()) {
			poses[key] = vector<int>();
		}
		poses[key].push_back(i);
		keys[i] = key;
		
		cnt[s[i] - 'a']++;
		cnt[s[i] - 'a'] %= 2;
	}
}

int hantenBit(int a, int pos) {
	if ((a >> pos) & 1) {
		return a - (1 << pos);
	}
	return a + (1 << pos);
}

int dp[200001];	//dp[文字数] = 最小分割数

int main() {
	cin >> s;
	setPoses();
	
	int i, j, k;
	
	for (i = 0; i <= s.length(); i++) dp[i] = 11451419;
	dp[0] = 0;
	
	for (i = 0; i < s.length(); i++) {
		int id = lower_bound(poses[keys[i]].begin(), poses[keys[i]].end(), i) - poses[keys[i]].begin();
		if (!(id == 0 || id == (int)poses[keys[i]].size() - 1)) continue;
		
		//偶分割
		if (poses.find(keys[i]) != poses.end()) {
			vector<int> &tmp = poses[keys[i]];
			int offset = upper_bound(tmp.begin(), tmp.end(), i) - tmp.begin();
			for (k = offset; k < tmp.size(); k++) {
				dp[tmp[k]] = min(dp[tmp[k]], dp[i] + 1);
			}
		}
		
		//奇分割
		for (j = 0; j < 26; j++) {
			//keys[i]のjビット目を反転
			int key = hantenBit(keys[i], j);
			if (poses.find(key) != poses.end()) {
				vector<int> &tmp = poses[key];
				int offset = upper_bound(tmp.begin(), tmp.end(), i) - tmp.begin();
				for (k = offset; k < tmp.size(); k++) {
					dp[tmp[k]] = min(dp[tmp[k]], dp[i] + 1);
				}
			}
		}
	}
	
	cout << dp[s.length()] << endl;
	return 0;
}
