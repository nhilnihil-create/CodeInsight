#include <bits/stdc++.h>
using namespace std;

string s;
int x, y;
bool a[2][16010];

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> s >> x >> y;
	s += 'T';
	a[0][8000] = true;
	a[1][8000] = true;
	int t = 0, f = 0;
	while(t < s.size() && s[t] == 'F') ++t;
		x -= t;
	for(int i=t; i<s.size(); ++i){
		if(s[i] != 'T') continue;
		if(i - t > 1){
//			cout << i - t - 1 << "\n";
			int u = i - t - 1;
			bool b[16010] = {};
			for(int j=0; j<16010; ++j){
				if(!a[f][j]) continue;
				if(0 <= j-u && j-u < 16010) b[j-u] = true;
				if(0 <= j+u && j+u < 16010) b[j+u] = true;
			}
			for(int j=0; j<16010; ++j) a[f][j] = b[j];
		}
		t = i;
		f = 1 - f;
	}
	if(0 <= 8000 + x && a[0][8000+x] && a[1][8000+y]) cout << "Yes\n";
	else cout << "No\n";
}