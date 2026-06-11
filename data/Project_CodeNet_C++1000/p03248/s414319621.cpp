#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FINISH {cout<<-1<<endl;return 0;}
const ll MOD = 1000000007;

vector<pair<int, int>> V = { {1,2} };

int main(){
	int n, tr = 1, ee = 3;
	string S;
	cin >> S;
	n = S.size();
	//前提チェック
	for (int i = 0;i < n - 1;i++) {
		if (S[i] != S[n - i - 2])FINISH;
	}
	if (S[0] == '0')FINISH;
	if (S[n - 1] == '1')FINISH;

	for (int i = 1;i < n - 1;i++) {
		if (S[i] == '1') {
			V.push_back(make_pair(tr, ee));
			swap(tr, ee);
			ee = tr + 1;
		}
		if (S[i] == '0') {
			V.push_back(make_pair(tr, ee));
			ee++;
		}
	}
	for (auto i : V) {
		cout << i.first << " " << i.second << endl;
	}
}