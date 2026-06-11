#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define INF 0x3f3f3f3f 
#define MEM(x,y) memset(x,y,sizeof(x))
#define int long long
#define rep(i , a , b) for(int i = a ; i <= b ; i ++)
#define P pair<int,int>
#define  sc(a) scanf("%lld",&a)
#define pf(a) printf("%lld ",a)
using namespace std;
signed main()
{
	int n;
	int k;
	cin >> n >> k;
	int ans = 0;
	rep(i, 1, n)
	{
		if (i >= k)
			ans += n - i;
	}
	rep(i, k+1, n)
	{
		ans += ((n - k) / i-1)*(i-k);
		ans += min((n - (n - k) / i*i-k) +1, i - k);
	}
	cout << ans;
}









