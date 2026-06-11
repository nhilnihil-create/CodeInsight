#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2e5+18;
int n;
int a[MAX_N];

ll go(const vector<int>& v)
{
	if(v[0]!=1) return -1;
	const int N = v.size();
	for(int i=1;i<N;++i)if(v[i]-v[i-1]>1) return -1;
	ll res = 1;
	for(int i=1;i<N;++i){
		if(v[i] == v[i-1] + 1) res++;
		else res+=v[i];
	}
	return res;
}

void solve()
{
	if(a[0]){
		cout<<-1<<'\n';
		return;
	}
	ll ans = 0;
	int idx = 1;
	while(idx < n){
		while(idx < n && !a[idx]) idx++;
		if(idx == n) break;
		vector<int> cur;
		while(idx<n && a[idx]){
			cur.push_back(a[idx++]);
		}
		ll res = go(cur);
		if(res == -1){
			cout<<-1<<'\n';
			return;
		}
		ans += res;
	}
	cout<<ans<<'\n';
}

int main()
{
	cin >> n;
	for(int  i=0;i<n;++i) cin >> a[i];
	solve();
	return 0;
}