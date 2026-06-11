#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int> dish(m);

	rep(i, n)							// n人分データを受け取る
	{
		int k, x;
		cin >> k;
		rep(j, k)						// 好きな料理として挙がったものをカウント
		{
			cin >> x;
			dish[x-1]++;
		}
	}

	rep(i, m) if (dish[i] >= n) ans++;	// 全員が好きだと答えた料理をカウント
	
	cout << ans << endl;
	return 0;
}