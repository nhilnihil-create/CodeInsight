#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
typedef long long ll;
const int MAX_H=2e5,MAX_W=2e5,MAX_N=2e5;
int H,W,N;
set<int> blk[MAX_W];
int main(){
	cin>>H>>W>>N;
	REP(i,N){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		blk[y].insert(x);
	}
	REP(i,W){
		blk[i].insert(H);
	}
	int ans=H;
	int x,y;
	x=y=0;
	do{
		auto ite=blk[y].upper_bound(x);
		ans=min(ans,*ite);
		if (y==W-1){
			break;
		}
		if (blk[y].find(x+1)!=blk[y].end() || x==H-1){
			break;
		}
		x++;
		if (blk[y+1].find(x)==blk[y+1].end()){
			y++;
		}
	}while(1);
	cout<<ans<<endl;
	return 0;
}