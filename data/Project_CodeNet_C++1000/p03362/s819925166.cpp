#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<int> ans;

bool is_p(int x)
{
	for(int i=2;i*i<=x;++i){
		if(x%i==0) return false;
	}
	return true;
}

void solve()
{
	for(int i=2;i<=55555;++i){
		if(is_p(i) && i%5==1) ans.push_back(i);
	}
	for(int i=0;i<N;++i) cout << ans[i] << ' ';
	cout << '\n';
}

int main()
{
	cin >> N;
	solve();
	return 0;
}