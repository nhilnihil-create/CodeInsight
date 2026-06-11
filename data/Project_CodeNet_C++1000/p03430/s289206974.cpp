#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int N = 100000 + 100;
const int MOD = 1000000007;
const int oo = 1e9;

string s;
int k,dp[301][301][301];

int calc(int l , int r , int rem){
	if(rem<0)return -oo;
	if(l==r)return 1;
	if(l>r)return 0;
	int &ret = dp[l][r][rem];
	if(ret != -1)return ret;
	ret = max(calc(l+1,r,rem),calc(l,r-1,rem));
	if(s[l]==s[r])
		ret = max(ret,2+calc(l+1,r-1,rem));
	if(s[l]!=s[r])
		ret = max(ret,2+calc(l+1,r-1,rem-1));
	return ret;
}
int main() {
	memset(dp,-1,sizeof dp);
	cin >> s>>k;
	cout << calc(0,s.size()-1,k) << endl;
	return 0;
}
