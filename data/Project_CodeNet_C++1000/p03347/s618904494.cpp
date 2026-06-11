#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>
using namespace std;
//#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
#define X first
#define Y second
#define all(o) o.begin(), o.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0), cin.tie(0)

int gcd(int x,int y){ return (!y ? x : gcd(y, x%y)); }
const int maxn = 1e6;
int a[maxn];
void fin(){
	cout << -1 << endl;
	exit(0);
}
int32_t main(){
	IOS;
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];
	if(a[0])
		fin();
	ll ans = 0;
	for(int i=1; i<n; i++){
		if(a[i] > a[i - 1] + 1)
			fin();
		if(a[i] == a[i - 1] + 1)
			ans++;
		else
			ans += a[i];
	}
	cout << ans << endl;
}
