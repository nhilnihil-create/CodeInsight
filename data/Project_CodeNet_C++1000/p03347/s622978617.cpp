///supercalifragilisticexpialidocious.
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <utility>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <bitset>
#include <complex>
using namespace std;
#define f first
#define s second
#define PB pop_back
#define pb push_back
#define mp make_pair
#define int long long
#define sz(s) (int)s.size()
#define seper(n) setprecision(n)
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long ll;
typedef map<int , int> mii;
typedef pair<int , int> pii;
typedef map<string , int> msi;
typedef pair<int , string> pis;
const int MAXN = 2e5 + 10;
int n , ans , a[MAXN];
int32_t main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
	if(a[0])
		return cout << -1 << endl , 0;
	for(int i = 0 ; i < n - 1 ; i ++)
	{
		if(a[i] + 1 < a[i + 1])
			return cout << -1 << endl , 0;
		if(a[i] + 1 == a[i + 1])
			ans ++;
		else 
			ans += a[i + 1];
	}
	return cout << ans << endl , 0;
}
