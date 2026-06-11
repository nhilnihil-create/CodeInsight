#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int len[10];
int n, A, B, C;

int dfs(int ind, int a, int b, int c){
	if(ind == n){
		if(a && b && c)return abs(a - A) + abs(b - B) + abs(c - C);
		return 1e9;
	}
	int ans = dfs(ind + 1, a, b, c);
	ans = min(ans, dfs(ind + 1, a + len[ind], b, c) + 10);
	ans = min(ans, dfs(ind + 1, a, b + len[ind], c) + 10);
	ans = min(ans, dfs(ind + 1, a, b, c + len[ind]) + 10);
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	cin>>n>>A>>B>>C;
	for(int i = 0; i < n; i++){
		cin>>len[i];
	}
	cout<<dfs(0, 0, 0, 0) - 30<<endl;

	return 0;
}