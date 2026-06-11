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



void topsort(int i, v<vi>& graph, vb& visit, stack<int>& res){
	visit[i] = true;
	
	for(int x : graph[i]){
		if(!visit[x])
		topsort(x,graph,visit,res);
	}
	res.push(i);
}

const int N = 100010;

ll dp[N];

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	dp[0] = 1;
	v<ll> prefix(k+1,0);
	
	for(int c = 0; c < n ; ++c){
		int max_candie;
		scanf("%d",&max_candie);
		for(int used = k; used >= 0 ; --used){
			int l = used +1;
			int r = used  + min(max_candie,k-used);
			if(l <= r){
				if(r+1 <= k)
					sub_self(prefix[r+1], dp[used]);
				add_self(prefix[l], dp[used]);
			}
		} 
		ll summ = 0;
		for(int i =0; i <= k; ++i){
			add_self(summ, prefix[i]);
			add_self(dp[i],summ);
			prefix[i] = 0;
		}
		
	}
	printf("%lld\n", dp[k]);			
	
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
