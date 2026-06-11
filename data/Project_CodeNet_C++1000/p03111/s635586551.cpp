#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using PL = pair<ll,ll>;

int n, a, b, c;
vector<int> l;
int nin = 1e6;


void dfs(int depth, int cost, int al, int bl, int cl) {
	if(depth == n) {
		if(al == 0 || bl == 0 || cl == 0)return ;
		if(cl > bl)swap(bl, cl);
		if(bl > al)swap(al, bl);
		if(cl > bl)swap(bl, cl);
		nin = min(abs(c - cl) + abs(b - bl) + abs(a - al) + cost, nin);
		return;
	}

	dfs(depth + 1, cost, al, bl, cl);
	dfs(depth + 1, cost + (al == 0 ? 0 : 10), al + l[depth], bl, cl);
	dfs(depth + 1, cost + (bl == 0 ? 0 : 10), al, bl + l[depth], cl);
	dfs(depth + 1, cost + (cl == 0 ? 0 : 10), al, bl, cl + l[depth]);
	return;
} 

int main()
{
	cin >> n >> a >> b >> c;
	l.resize(n);
	for(int i = 0; i < n; i++)cin >> l[i];
	dfs(0, 0, 0, 0, 0);
	cout << nin << endl;
}