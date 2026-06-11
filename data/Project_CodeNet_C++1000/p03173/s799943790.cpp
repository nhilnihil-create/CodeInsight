//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <map>
//#include <iostream>
//#include <algorithm>
//#include <set>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pil = pair<int,ll>;
using vi = vector<int>;
using vb = vector<bool>;
using pli = pair<ll,int>; 		
#define fi first
#define v vector
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
int INF = 1e9+7;
ll inf = 1e18+7;
int MOD = 1e9+7;

void add_self(auto &a, auto b){
	a += b;
	if(a >= MOD){
		a -= MOD;
	}
}

void sub_self(auto &a, auto b){
	a -= b;
	if(a < 0)	a += MOD;
}

void max_self(auto &a, auto b){
	if(b > a)	a = b;
}

void min_self(auto &a, auto b){
	if(b < a)	a = b;
}

void topsort(int i, v<vi>& graph, vb& visit, stack<int>& res){
	visit[i] = true;
	
	for(int x : graph[i]){
		if(!visit[x])
		topsort(x,graph,visit,res);
	}
	res.push(i);
}
const int N  = 510;
ll dp[N][N];


void solve(){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			dp[i][j]=  inf;
		}
	}
	int n;
	scanf("%d",&n);
	v<ll> arr(n);
	v<ll> prefix;
	prefix.pb(0);
	for(int i = 0; i < n; ++i){
		scanf("%lld",&arr[i]);
		prefix.pb(prefix.back() + arr[i]);
	}
	
	
	for(int l = n-1; l >= 0; --l){
		for(int r = l; r < n; ++r){
			if(l == r){
				dp[l][r] = 0;
				continue;
			}
			for(int i = l; i <= r-1; ++i){
				min_self(dp[l][r], dp[l][i] + dp[i+1][r] + prefix[r+1] - prefix[l]);
			}
		}
	}
	
	
	
	
	printf("%lld\n", dp[0][n-1]);
}	



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	//cin >> t;
	//scanf("%d",&t);
	while(t--){
		solve();
	}
		
			
}
