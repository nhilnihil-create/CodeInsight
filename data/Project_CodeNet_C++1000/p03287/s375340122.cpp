#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <cstring>

#define ll long long
#define ld long double
#define HS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
#define point complex <double> 
#define pi acos(-1)
#define mod 1000000007


using namespace std;


int main() {
	HS;
	int n, m;
	cin >> n >> m;
	ll sum = 0,ans=0;
	map< int, int > cnt,zer;
	cnt[0] = 1;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		sum += x;
		ans += cnt[sum % m];
		cnt[sum % m]++;
	}
	cout << ans << endl;
	


	return 0;
}