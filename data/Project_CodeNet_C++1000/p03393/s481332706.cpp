#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	cin >> S;
	vector<int> alp(26);
	rep(i,S.size()) alp[S[i]-'a']++;
	rep(i,26) if (alp[i] == 0) {
		S += (char)('a'+i);
		cout << S << endl;
		return 0;
	}

	for (int i = S.size()-1; i >0; i--) {
		if (S[i-1] > S[i]) continue;
		for (int j = S.size()-1; j >i-1; j--) {
			if (S[i-1] > S[j]) continue;
			swap(S[i-1], S[j]);
			break;
		}
		S = S.substr(0, i);
		cout << S << endl;
		return 0;
	}
	cout << -1 << endl;

	return 0;
}
