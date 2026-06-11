#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
vector<int> enum_div(int n)//nの約数を列挙
{
	vector<int> ret;
	for(int i=1 ; i*i<=n ; ++i)
	{
		if(n%i == 0)
		{
			ret.push_back(i);
			if(i*i!=n)
			{
				ret.push_back(n/i);
			}
		}
	}
	return ret;
}
map<int, int> used;
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> v = enum_div(n);
    // REP(i, 1, n) {
    //     if(n / i == n % i) cout << i << " " << n / i << " " << n % i << endl;
    //     //cout << i << " " << n / i << " " << n % i << endl;
    // }
    int ans = 0;
    for(auto e: v) {
        int num1 = e - 1;
        int num2 = e + 1;
        if(!used[num1] && num1 > 0 && n / num1 == n % num1) ans += num1;
        if(!used[num2] && n / num2 == n % num2) ans += num2;
        used[num1] = true;
        used[num2] = true;
    }
    cout << ans << endl;

    return 0;
}
