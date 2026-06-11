#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 100009;
int N, C;
int s[MAX_N],t[MAX_N],c[MAX_N];

int used[35][MAX_N];

void solve()
{
	for(int i=0;i<N;++i) used[c[i]][s[i]-1]++, used[c[i]][t[i]]--;
	for(int ch=1;ch<=C;++ch)for(int t=1;t<MAX_N;++t) used[ch][t] += used[ch][t-1];
	
	int ans = 0;
	for(int i=0;i<MAX_N;++i){
		int cur = 0;
		for(int j=1;j<=C;++j)if(used[j][i])cur++;
		ans = max(ans, cur);
	}
	cout << ans << '\n';
}

int main()
{
	cin >> N >> C;
	for(int i=0;i<N;++i){
		cin >> s[i] >> t[i] >> c[i];
	}
	solve();
	return 0;
}