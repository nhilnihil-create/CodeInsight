#include<bits/stdc++.h>
using namespace std;

const int N = 305;
typedef long long ll;

string s;
int n, m, f[N][N][N];

int Dfs(int l, int r, int p) {
	if(f[l][r][p]) return f[l][r][p];
	if(l == r) return f[l][r][p] = 1;
	if(l + 1 == r) {
		if(p || s[l] == s[r]) return f[l][r][p] = 2;
		else return f[l][r][p] = 1;
	}
	if(s[l] == s[r]) f[l][r][p] = max(f[l][r][p], Dfs(l + 1, r - 1, p) + 2);
	else if(p) f[l][r][p] = max(f[l][r][p], Dfs(l + 1, r - 1, p - 1) + 2);
	return f[l][r][p] = max(f[l][r][p], max(Dfs(l, r - 1, p), Dfs(l + 1, r, p)));
}

int main() {
	cin>>s>>m;
	n = s.size();
	cout<<Dfs(0, n - 1, m)<<endl;
	return 0;
}