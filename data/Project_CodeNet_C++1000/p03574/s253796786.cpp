#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int h,w;
	cin >> h >> w;
	vector<vector<char>> s(h, vector<char>(w));
	rep(i,h)rep(j,w) cin >> s[i][j];
	int counts = 0;
	rep(i,h)rep(j,w){
		if(s[i][j] == '.'){
			s[i][j] = '0';
			for(int x = -1; x <=1; x++){
				for(int y = -1; y <= 1; y++){
					int nx = i+x;
					int ny = j+y;
					if(nx >= 0 && nx < h && ny >= 0 && ny < w && s[nx][ny] == '#')	s[i][j]++;
				}
			}
		}
	}
	rep(i,h){
		rep(j,w){
			cout << s[i][j];
		}
		cout << endl;
	}
}