#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
int main(){
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;
	vector<pair<char, int>> E;
	E.push_back(make_pair(S[0], 1));
	for (int i = 1; i < N; i++){
		if (S[i] == E.back().first){
			E.back().second++;
		} else {
			E.push_back(make_pair(S[i], 1));
		}
	}
	int cnt = E.size();
	vector<int> s(cnt + 1, 0);
	for (int i = 0; i < cnt; i++){
		s[i + 1] = s[i] + E[i].second;
	}
	int ans = 0;
	for (int i = 0; i < cnt; i++){
		if (E[i].first == '0'){
			ans = max(ans, s[min(cnt, i + K * 2)] - s[i]);
		} else {
			ans = max(ans, s[min(cnt, i + K * 2 + 1)] - s[i]);
		}
	}
	cout << ans << endl;
}