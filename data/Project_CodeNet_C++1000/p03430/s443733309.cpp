#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000 + 10;
const int M = 1000000007;
const double eps = 1e-9;
const double PI = acos(-1);
const int oo = 1000000000;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
#define pb push_back 
#define all(c) (c).begin(),(c).end()
string s;
int k,dp[301][301][301];
int calc(int a, int b, int t){
	if(t<0)return -oo;
	if(a==b)return 1;
	if(a>b)return 0;
	int &ret=dp[a][b][t];
	if(ret+1)return ret;
	ret=max(calc(a+1,b,t), calc(a, b-1, t));
	ret=max(ret, 2+calc(a+1,b-1,t-1));
	if(s[a]==s[b])
		ret=max(ret, 2+calc(a+1,b-1,t));
	return ret;
}
int main(){
	cin>>s>>k;
	memset(dp,-1,sizeof(dp));
	cout<<calc(0,s.size()-1, k)<<endl;
	return 0;	
}