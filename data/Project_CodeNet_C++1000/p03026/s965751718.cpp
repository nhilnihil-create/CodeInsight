#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <stdio.h>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> M(n);
	vector<int> a(n-1),b(n-1);
	rep(i,n-1)
	{
		int foo,fooo;
		cin >> foo >> fooo;
		foo--;fooo--;
		M[foo].push_back(fooo);
		M[fooo].push_back(foo);
		a[i]=foo;
		b[i]=fooo;
	}
	vector<int> weight(n);
	rep(i,n)cin >> weight[i];
	sort(ALL(weight));
	vector<int> ans(n);
	stack<int> S;

	S.push(0);
	ans[0]=ans.back();
	ans.pop_back();

	while(!S.empty())
	{
		int now = S.top();
		if(ans[now]==0)
		{
			ans[now]=weight.back();
			weight.pop_back();
		}
		int next = -1;
		rep(i,M[now].size())
		{
			if(ans[M[now][i]]==0)
			{
				S.push(M[now][i]);
				next = M[now][i];
			}	
		}
		if(next==-1)S.pop();
	}
	int sum = 0;
	rep(i,n-1)
	{
		sum += min(ans[a[i]],ans[b[i]]);
	}
	cout<<sum<<endl;
	rep(i,n)
	cout<<ans[i]<<endl;



	
	

	return 0;
}