#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	int H,W;
	cin >> H >> W;
	vector<string> S(H);
	rep(i,H) cin >> S[i];

	rep(i,H)rep(j,W) {
		if(S[i][j] == '.') {
			S[i][j] = '0';
			for(int k=-1; k<=1; k++) {
				for(int l=-1; l<=1; l++) {
					int h = i+k, w = j+l;
					if(0<=h && h<H && 0<=w && w<W) {
						if(S[h][w] == '#') S[i][j]++;
					}
				}
			}
		}
	}
  rep(i,H) cout << S[i] << endl;
}