#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main()
{
	int N, M, C;
	cin >> N >> M >> C;
	vector<vector<int> > nmVec(N, vector<int>(M));
	vector<int> bVec(M);
	int ans = 0;
	rep(j, M)cin >> bVec.at(j);

	rep(i, N) {
		int count = 0;
		rep(j, M) {
			cin >> nmVec.at(i).at(j);
			count += nmVec.at(i).at(j) * bVec.at(j);
		}
		count += C;
		if (count>0)
		{
			ans++;
		}
	}
	cout << ans << endl;
}