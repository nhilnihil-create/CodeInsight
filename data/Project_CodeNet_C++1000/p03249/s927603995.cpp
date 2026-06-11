#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define mod 1000000007
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define long long long
inline int rei(){int x;cin>>x;return x;}
inline long rel(){long x;cin>>x;return x;}
inline string res(){string x;cin>>x;return x;}
//------------------------------------------------------- 
pair<long,int> D[100000];
int child[100000];
pair<int,int> ans[99999];
long childsum[100000];
void Calc(){
	int N = rei();
	for(int i=0;i<N;i++){
		long d = rel();
		D[i] = {d,i};
	}
	sort(D,D+N);
	for(int i=N-1;i>0;i--){
		long c = D[i].first + 2*child[D[i].second] + 2 - N;
		int bf = 0;
		int bl = N;
		while(bf != bl){
			int bc = (bf+bl)/2;
			if(bc == N || D[bc].first >= c){
				bl = bc;
			}
			else{
				bf = bc+1;
			}
		}
		if(D[bf].first == c){
			child[D[bf].second] += child[D[i].second]+1;
			childsum[D[bf].second] += childsum[D[i].second]+child[D[i].second]+1;
			ans[i] = {D[bf].second,D[i].second};
		}
		else{
			cout << -1 << endl;
			return;
		}
	}
	if(D[0].first != childsum[D[0].second]){
		cout << -1 << endl;
		return;
	}
	for(int i=1;i<N;i++){
		cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
	}
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}