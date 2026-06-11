#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> fwd;
vector<vector<int>> bwd;
vector<int> dp;

int len(int v)
{
	if(dp[v] != 0)
		return dp[v];
	int result = 0;
	for(int ne : fwd[v])
		result = max(result, len(ne)+1);
	return dp[v] = result;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	fwd.resize(n);
	bwd.resize(n);
	dp.resize(n);
	for(int i = 0; i < m; i++)
	{
		int xi,yi;
		cin >> xi >> yi;
		//cout << xi << "->" << yi << endl;
		xi--;
		yi--;
		fwd[xi].push_back(yi);
		bwd[yi].push_back(xi);
	}
	vector<int> starts;
	for(int i = 0; i < n; i++)
	{
		if(bwd[i].size() == 0 && fwd[i].size() != 0){
			starts.push_back(i);
		}
	}

	int best = 0;
	for(int v : starts)
		best = max(best, len(v));
	cout << best << endl;
}
