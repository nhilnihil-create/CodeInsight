#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
const int N = 1e3+5, mod = 1e9+7;
int n, a[N];
vector<pair<int, int>> ans;
void solvePOS()
{
	for(int i=1; i<n; i++) ans.push_back({i, i+1});
}
void solveNEG()
{
	for(int i=n-1; i>0; i--) ans.push_back({i+1, i});
}
void print()
{
	cout << ans.size() << endl;
	for(auto i : ans) cout << i.f << " " << i.s << endl;
}
int main()
{
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	int mn = *min_element(a, a+n);
	int mx = *max_element(a, a+n);
	if(mn >= 0) solvePOS();
	else if(mx <= 0) solveNEG();
	else if(mx >= abs(mn))
	{
		int l = find(a, a+n, mx)-a + 1;
		for(int i=0; i<n; i++) if(a[i] < 0) ans.push_back({l, i+1});
		solvePOS();
	}
	else
	{
		int l = find(a, a+n, mn)-a + 1;
		for(int i=0; i<n; i++) if(a[i] > 0) ans.push_back({l, i+1});
		solveNEG();
	}
	print();
}