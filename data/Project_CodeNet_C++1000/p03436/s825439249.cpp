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
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int h,w;
	cin >> h >> w;
	vector<string> s(h);
	REP(i,h) cin >> s[i];
	
	vector<vector<int>> E(h*w); 
	int dotmasu=0;
	REP(i,h){
		REP(j,w){
			if(s[i][j]=='#') continue;
			
			dotmasu++;
			if(i!=h-1 && s[i+1][j]=='.'){
				E[i*w+j].push_back((i+1)*w+j);
				E[(i+1)*w+j].push_back(i*w+j);
			}
			if(j!=w-1 && s[i][j+1]=='.'){
				E[i*w+j].push_back(i*w+(j+1));
				E[i*w+(j+1)].push_back(i*w+j);
			}
		}
	}
	
	queue<pair<int,int>> q;
	vector<int> count(h*w, -1);
	count[0] = 1;
	q.push({0,1});
	while(!q.empty()){
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();
		
		for(auto child: E[now]){
			if(count[child]==-1){
				count[child] = dist+1;
				q.push({child, dist+1});
			}
		}
	}
	
	if(count[h*w-1]==-1){
		cout << -1 << endl;
	}else{
		cout << dotmasu - count[h*w-1] << endl;
	}
	
	return 0;
}