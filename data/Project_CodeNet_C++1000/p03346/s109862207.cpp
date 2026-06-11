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
const int maxn = 1e6 + 10;
int a[maxn], pos[maxn], dp[maxn];
int32_t main(){
	IOS;
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
		a[i]--;
		pos[a[i]] = i;
	}
	dp[n - 1] = 1;
	int ans = 1;
	for(int i=n-2; i>=0; i--){
		dp[i] = (pos[i+1] > pos[i] ? dp[i+1] + 1 : 1);
		ans = max(ans, dp[i]);
	}
	cout << n - ans << endl;
}
