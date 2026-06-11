#include <bits/stdc++.h>

using namespace std;

int f[16666], g[16666];
string s;
int t[2], n[2], z;
int a[2][8888];

int main(){
//	freopen("input.inp", "r", stdin);
	cin >> s >> t[0] >> t[1];
	int dir = -1;
	for(int i = 0; i < s.length(); ++i){
		if (s[i] == 'F'){
			if (dir == -1) ++z;
			else ++a[dir][n[dir]];
		}
		else{
			if (dir == -1) dir = 1;
			else dir ^= 1;
			++n[dir];
		}
	}
	//0->x;
	t[0] = abs(t[0] - z); 
	t[1] = abs(t[1]);
	for(int k = 0; k < 2; ++k){
		sort(a[k] + 1, a[k] + 1 + n[k]);
		reverse(a[k] + 1, a[k] + 1 + n[k]);
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		int mx = 0;
		f[0] = g[0] = 1;
		for(int i = 1; i <= n[k]; ++i){
			mx += a[k][i];
			for(int j = 0; j <= mx; ++j){
				f[j] = 0;
				if (j >= a[k][i]) f[j] |= g[j - a[k][i]];
				if (j + a[k][i] <= mx) f[j] |= g[j + a[k][i]];
			}
			for(int j = 0; j <= mx; ++j) g[j] = f[j];
		}
		if (!f[t[k]]){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}