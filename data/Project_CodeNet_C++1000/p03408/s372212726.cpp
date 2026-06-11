#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef pair<int, int> P;

int N, M;
map<string, int> score;

int main() {
	cin >> N;
	rep(i, N) {
		string tmp;
		cin >> tmp;
		score[tmp] ++;
	}
	cin >> M;
	rep(i, M) {
		string tmp;
		cin >> tmp;
		score[tmp]--;
	}
	int maxNum = -1000;
	string ans;
	rep(i, score.size()) {
		for (auto p : score) {
			if (p.second > maxNum) {
				maxNum = p.second;
			}
		}
	}
	if (maxNum < 0) {
		cout << 0 << endl;
	}
	else {
		cout << maxNum << endl;
	}
	
}