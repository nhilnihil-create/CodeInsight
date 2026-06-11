#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>
#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const int INF = INT_MAX/10;
const ll MOD = 1e9+7;
int a[212345],opt[212345],dp[1<<26];
int main(){
	string s;
	cin>>s;
	int N=s.length();
	repeat(i,N)
		a[i+1]=a[i]^(1<<(s[i]-'a'));
	fill(opt,opt+N+1,INF);
	fill(dp,dp+(1<<26),INF);
	opt[0]=0;
	dp[0]=0;
	for(int i=1;i<=N;++i){
		opt[i]=dp[a[i]]+1;
		for(int x=1;x<(1<<26);x<<=1)
			opt[i]=min(opt[i],dp[a[i]^x]+1);
		dp[a[i]]=min(dp[a[i]],opt[i]);
	}
	cout<<opt[N]<<endl;
	return 0;
}
