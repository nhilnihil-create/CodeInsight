#include <bits/stdc++.h>

using namespace std;

int dp1[2][32010], dp2[2][32010], *DP1[2] = {(dp1[0]+16005),(dp1[1]+16005)}, *DP2[2] = {(dp2[0]+16005),(dp2[1]+16005)};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int x, y, c = 0, cur = 0, t = 0;
	vector<int> xmoves, ymoves;
	cin >> s;
	cin >> x >> y;
	s += 'T';
	for (int i = 0; i < s.size(); ++i){
		t++;
		if (s[i] == 'F'){
			cur++;
			t--;
		}
		else if (cur){
			if (!c){
				if (t == 1){
					x -= cur;
				}
				else xmoves.push_back(cur);
				cur = 0;
				c = 1;
			}
			else{
				ymoves.push_back(cur);
				cur = 0;
				c = 0;
			}
		}
		else{
			c = 1 - c;
		}
	}
	DP1[0][0] = 1;
	for (int i = 1; i <= xmoves.size(); ++i){
		for (int j = -8000; j <= 8000; ++j){
			DP1[i&1][j] = (DP1[(i-1)&1][j-xmoves[i-1]] | DP1[(i-1)&1][j+xmoves[i-1]]);
		}
	}
	DP2[0][0] = 1;
	for (int i = 1; i <= ymoves.size(); ++i){
		for (int j = -8000; j <= 8000; ++j){
			DP2[i&1][j] = (DP2[(i-1)&1][j-ymoves[i-1]] | DP2[(i-1)&1][j+ymoves[i-1]]);
		}
	}
	if (DP1[((int)xmoves.size())&1][x] && DP2[((int)ymoves.size())&1][y]){
		cout << "Yes\n";
	}
	else cout << "No\n";
	cout << flush;
	//for (int i = 0; i < 1e9; ++i){for (int j = 0; j < 1e9; ++j){}}
}