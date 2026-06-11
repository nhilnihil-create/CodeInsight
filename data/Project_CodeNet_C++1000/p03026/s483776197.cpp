#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;
 
int N, a, b, c[100000], res[100000];
ll ans;
bool vis[100000];
priority_queue<int>q;
vector<int>v[100000];
 
void dfs(int x) {
	vis[x] = true;
	res[x] = q.top();
	ans += q.top();
	q.pop();
	for (int i : v[x]) {
		if (!vis[i]) {
			dfs(i);
		}
	}
}
 
 
int main() {
	cin >> N;
	for (int i = 1; i < N; ++i) {
		cin >> a >> b; --a; --b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < N; ++i) {
		cin >> c[i];
		q.push(c[i]);
	}
	ans = -q.top();
	dfs(0);
	cout << ans << endl;
	for (int i = 0; i < N; ++i) {
		cout << res[i];
		if(i!=N-1)cout << ' ';
		else cout << endl;
	}
}