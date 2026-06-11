#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
ld EPS = 1e-12;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;
#define rep(i,n) for(int i = 0; i < n; i++)
#define all(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << '\n'

char mp[105][105];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int a,b;
    cin >> a >> b;
	for(int i = 1; i <= 50; i++)
		for(int j = 1; j <= 100; j++)
			mp[i][j]='.';
	for(int i = 51; i <= 100; i++)
		for(int j = 1; j <= 100; j++)
			mp[i][j]='#';
	b--;
	for(int i = 1; i <= 50 && b; i += 2)
		for(int j = 1; j <= 100 && b; j += 2)
			mp[i][j]='#',b--;
	a--;
	for(int i = 100; i > 50 && a; i -= 2)
		for(int j = 1; j <= 100 && a; j += 2)
			mp[i][j]='.',a--;
	cout << "100 100" << endl;
	for(int i = 1; i <= 100; i++, cout << '\n')
		for(int j = 1; j <= 100; j++)
			cout << mp[i][j];
}