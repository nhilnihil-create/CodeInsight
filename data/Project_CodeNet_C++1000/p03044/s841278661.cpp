#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	ll n;
	cin >> n;
	vector<vector<pair<int,int>>> v(n); // {v, distance}
	REP(i,n-1){
		int a,b,c;
		cin >> a >> b >> c;
		a--; b--; // 0-based
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	
	queue<int> q;
	vector<int> cost(n,0);
	q.push(0);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		for(auto x: v[now]){
			int child = x.first;
			if(cost[child]!=0) continue;
			cost[child] = cost[now]+x.second;
			q.push(child);
		}
	}
	
	cout << 0 << endl;
	FOR(i, 1, n){
		if(cost[i]%2){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
	}
 	
	
	return 0;
}