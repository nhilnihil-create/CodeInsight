#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;
static long long INF = (1LL<<62);
using LLPair = pair<LL, LL>;

void bfs_grid(LL H, LL W, vector<string> &s, vector<vector<LL>> &D, char start, char wall = '#'){
	const int dh[4] = {1, 0, -1, 0};
	const int dw[4] = {0, 1, 0, -1};

	D.assign(H, vector<LL>(W, -1));
	queue<LLPair> Q;
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			if(s[i][j] == start){
				Q.push(make_pair(i, j));
				D[i][j] = 0;
			}
		}
	}
	while(!Q.empty()){
		auto p = Q.front(); Q.pop();
		LL ch = p.first;
		LL cw = p.second;
		for(int i=0; i<4; i++){
			LL nh = ch + dh[i];
			LL nw = cw + dw[i];
			if(nh < 0 || nw < 0 || nh >= H || nw >= W){
				continue;
			}
			if(D[nh][nw] != -1 || s[nh][nw] == wall){
				continue;
			}
			Q.push(make_pair(nh, nw));
			D[nh][nw] = D[ch][cw] + 1;
		}
	}
}

int main(int argc, char* argv[]){
	LL H, W;
	cin >> H >> W;
	vector<string> S;
	int wall = 0;
	for(int i=0; i<H; i++){
		string s;
		for(int j=0; j<W; j++){
			char c; cin >> c;
			s.push_back(c);
			if(c == '#'){
				wall++;
			}
		}
		S.push_back(s);
	}
	S[0][0] = 's';

	vector<vector<LL>> D;
	bfs_grid(H, W, S, D, 's');

	LL d = D[H-1][W-1];
	if(d == -1){
		printf("-1\n");
		return 0;
	}
	else{
		LL ans = H*W - wall - (d+1);
		printf("%lld\n", ans);
	}
	return 0;
}