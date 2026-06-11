#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	string S, T;
	cin >> S >> T;
	if(S.size() < T.size()) {
		cout << "UNRESTORABLE\n";
		return 0;
	}
	vector<int> candidate;
	for(int i = 0; i <= S.size() - T.size(); i++) {
		if(S[i] == T[0] || S[i] == '?') {
			bool ok = true;
			for(int j = 1; j < T.size(); j++)
				if(S[i + j] != T[j] && S[i + j] != '?') {
					ok = false;
					break;
				}
			if(ok) candidate.push_back(i);
		}
	}
	if(candidate.size() == 0) {
		cout << "UNRESTORABLE\n";
		return 0;
	}
	vector<string> answers;
	for(int i = 0; i < candidate.size(); i++) {
		string tmp = S;
		for(int j = 0; j < S.size(); j++) {
			if(S[j] == '?') {
				if(candidate[i] <= j && j < candidate[i] + T.size())
					tmp[j] = T[j - candidate[i]];
				else
					tmp[j] = 'a';
			}
		}
		answers.push_back(tmp);
	}
	sort(answers.begin(), answers.end());
	cout << answers[0] << "\n";
	return 0;
}
