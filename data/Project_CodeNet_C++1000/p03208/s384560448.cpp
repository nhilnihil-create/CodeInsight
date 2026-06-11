#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	vector<int> h(n);
	for(int i=0;i<n;i++)
	{
		cin >> h.at(i);
	}
	sort(h.begin(),h.end());
	int ans=1000000000;
	for(int i=0;i<n-k+1;i++)
	{
		int d=h.at(i+k-1) - h.at(i);
		ans = min(ans,d);
	}
	cout << ans << endl;
	return 0;
}
