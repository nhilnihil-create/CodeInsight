#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <math.h>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
#define rep(i,n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1<<30;
const int mod = 1000000007;

int main(){
	int a, b;
	cin >> a >> b;
	char ans = 'x';
	if(a+b==15) ans = '+';
	else if(a*b==15) ans = '*';
	cout << ans << endl;
	return 0;
}
