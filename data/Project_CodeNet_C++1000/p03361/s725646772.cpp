#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int h,w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i,h) cin >> s[i];
	int countsA = 0;
	int countsB = 0;
	bool ok = true;
	rep(i,h)rep(j,w){
		if(s[i][j] == '.') continue;
				countsA = 0;
				countsB = 0;
				int nx = i + 1;
				int nx1 = i - 1;
				int ny = j + 1;
				int ny1 = j - 1;
				if(nx >= 0 && nx < h && s[nx][j] == '.') countsA++;
				if(nx1 >= 0 && nx1 < h && s[nx1][j] == '.') countsA++;
				if(ny >= 0 && ny < h && s[i][ny] == '.') countsA++;
				if(ny1 >= 0 && ny1 < h && s[i][ny1] == '.') countsA++;
				if(nx >= 0 && nx < h) countsB++;
				if(nx1 >= 0 && nx1 < h) countsB++;
				if(ny >= 0 && ny < h) countsB++;
				if(ny1 >= 0 && ny1 < h) countsB++;
				if(countsB == countsA) ok = false;
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}