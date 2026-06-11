#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>
#include <cmath>

using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);++(i))

string s;
int x;
int y;

bool f = true;

bool ok(vector<int>& d , int A)
{
	vector<bool> dp(20000,false);
	auto acc = [](int i){
		return i + 10000;
	};

	dp[acc(0)] = true;

	for(int i = 0;i < d.size();i++)
	{
		vector<bool> before = move(dp);
		dp.assign(20000,false);
		for(int j = -10000;j < 10000;j++)
		{
			int index = acc(j);
			if(index + d[i] < dp.size() && !f)
				dp[index] = dp[index] || before[index + d[i]];
			if(0 <= index - d[i])
				dp[index] = dp[index] || before[index - d[i]];
		}
      	f =  false;
	}


	return dp[acc(A)];
}
int main()
{
	cin >> s >> x >> y;

	vector<int> d[2];


	int now = 0;
	int cou = 0;

	for(char c : s)
	{
		if(c == 'T')
		{
			d[now].push_back(cou);
			now = 1 - now;
			cou = 0;
		}
		else
		{
			cou++;
		}
	}

	if(cou != 0)
	{
		d[now].push_back(cou);
	}

	if(ok(d[0],x) && ok(d[1] , y))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

}


