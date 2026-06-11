#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main()
{
	int n;
	cin >> n;
	vector<int> b(n);
	rep(i,n)cin >> b[i];
	rep(i,n)
	{
		if(b[i]>i+1)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	vector<int> ans;
	//ans.push_back(0);
	rep(i,n)
	{
		ans.insert(ans.begin()+b[i]-1,b[i]);
	}
	rep(i,n)cout<<ans[i]<<endl;
	return 0;
}