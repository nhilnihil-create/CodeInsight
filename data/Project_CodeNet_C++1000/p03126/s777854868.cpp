#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	map<int, int> M;
	int i, j, k;
	for(i=1; i<=n; i++){
		cin >> k;
		for(j=1; j<=k; j++){
			int x;
			cin >> x;
			M[x]++;
		}
	}
	int count = 0;
	for(auto it = M.begin(); it!=M.end(); it++){
		if(it->second == n) count++;
	}
	cout << count << endl;
	return 0;
}
