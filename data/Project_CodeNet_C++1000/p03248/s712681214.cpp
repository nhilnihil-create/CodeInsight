#include "bits/stdc++.h"
using namespace std;
template <typename T> void IN(T& t){ cin >> t; }
template <typename T, typename ... U> void IN(T& t, U& ... u){ IN(t); IN(u ...); }
template <typename T> void OUT(T t){ cout << t; }
template <typename T, typename ... U> void OUT(T t, U ... u){ OUT(t); OUT(u ...); }
//#define int long long
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define size(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define ROF(i,b,a) for(int i=b; i>=a; --i)
using LL = long long;
using pii = pair<int,int>;
const int INF = 2e9;
const int NN = 1e5 + 3;

string s;
vector<int> adj[NN];

int32_t main(){ FAST;
	IN(s);
	int n = size(s);
	bool possible = true;
	FOR(i,0,n-2) if(!(s[i] == s[n-2-i])) possible = false;
	if(!(s[0] == '1')) possible = false;
	if(!(s[n-1] == '0')) possible = false;

	if(!possible){
		OUT(-1, "\n");
		return 0;
	}

	OUT(1, " ", 2, "\n");
	reverse(all(s));
	int cur = 2;
	while(cur <= n-1){
		int nxt = cur+1;
		while(!(s[nxt-1] == '1')) ++nxt;
		FOR(i,cur+1,nxt) OUT(cur, " ", i, "\n");
		cur = nxt;
	}
}