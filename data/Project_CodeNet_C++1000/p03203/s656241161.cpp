#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+15;
vector<int> d[N];
void solve(){
	int h,w,n;
	set<pair<int,int> > s;
	scanf("%d%d%d",&h,&w,&n);
	for(int i=0;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if(!s.count(make_pair(x,y))){
			d[x].push_back(y);
			s.insert(make_pair(x,y));
		}
	}
	for(int x=1;x<=h;++x){
		sort(d[x].begin(),d[x].end());
	}
	int y = 1;
	for(int x = 1;x<=h;++x){
		int ind = lower_bound(d[x+1].begin(),d[x+1].end(),y+1) - d[x+1].begin();
		if(ind>0){
			printf("%d\n", x);
			return;
		}
		if(!s.count(make_pair(x+1,y+1))){
			++y;
		}
	}
	printf("%d\n", h);
}
int main(){
	//freopen("input.txt","r",stdin);
	solve();
}