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
const int maxn = 300 + 10;
int dp[maxn][maxn][maxn];
int32_t main(){
	IOS;
	string s;
	cin >> s;
	int n = s.size(), k1;
	cin >> k1;
	for(int k=0; k<=k1; k++){
		for(int sz=1; sz<=n; sz++){
			for(int i=0; i+sz<=n; i++){
				int j = i+sz;
				if(sz == 1){
					dp[k][i][j] = 1;
					continue;
				}
				if(s[i] == s[j-1]){
					dp[k][i][j] = dp[k][i+1][j-1]+2;
					continue;
				}
				int x = dp[k][i+1][j];
				x = max(x, dp[k][i][j-1]);
				if(k) 
					x = max(x, dp[k-1][i+1][j-1] + 2);
				dp[k][i][j] = x;
			}
		}
	}
	cout << dp[k1][0][n] << endl;
}
