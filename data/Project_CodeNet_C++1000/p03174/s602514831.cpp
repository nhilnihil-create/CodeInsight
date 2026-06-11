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
#define forn(i,n) for(int i = 0; i < n; ++i)
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

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

int match(int i, int n, int mask, v<vb>& mat, v<vi>& m){
	if(m[i][mask] != -1){
		return m[i][mask];
	}
	if(i >= n)	{
		for(int i1 = 0; i1 < n; ++i1){
			if( (mask >> i1) & 1){
				continue;
			}
			else{
				return 0;
			}
		}
		return 1;
	}
	
	int ans = 0;
	for(int w = 0; w < n; ++w){
		if(mat[i][w] && ( (mask>>w) & 1) == 0) {
			int temp= 1 << w;
			add_self(ans, match(i+1,n,(mask|temp),mat,m)); 
		}
	}
	m[i][mask] = ans;
	return ans;
}

void solve(){
	int n;
	scanf("%d",&n);
	int MAXX = pow(2,n)+2;
	v<vb> mat(n,vb(n,0));
	v<vi> m(n+1, vi(MAXX,-1));
	forn(i,n){
		forn(j,n){
			int temp;
			scanf("%d",&temp);
			mat[i][j] = temp;
		}
	}
	
	//unordered_map<pii,int,hash_pair> m;
	
	printf("%d\n", match(0,n,0,mat,m));
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
