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

void max_self(auto &a, auto b){
	if(b > a)	a = b;
}

void topsort(int i, v<vi>& graph, vb& visit, stack<int>& res){
	visit[i] = true;
	
	for(int x : graph[i]){
		if(!visit[x])
		topsort(x,graph,visit,res);
	}
	res.push(i);
}

const int N = 100010;

bool dp[N];

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	vi arr(n);
	for(int i = 0; i < n ; ++i){
		scanf("%d",&arr[i]);
	}
	sort(arr.begin(), arr.end());
	for(int left = 0; left <= k; ++left){
		for(int add : arr){
			if(add + left > k)	break;
			dp[add + left] = dp[add + left] || (!dp[left]);
		}
	}
	if(dp[k] == true){
		printf("First\n");
	}
	else{
		printf("Second\n");
	}
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
