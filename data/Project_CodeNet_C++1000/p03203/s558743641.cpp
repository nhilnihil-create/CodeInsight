#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e5+15;

vector<int> d[N];

int mini[N];

set<int> mm[N];

void solve(){
	int h,w,n;
	scanf("%d%d%d",&h,&w,&n);
	set<pair<int,int> >s;
	for(int y=1;y<=w;++y){
		mini[y] = h;
	}
	for(int i=0;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if(s.count(make_pair(x,y))){
			continue;
		}
		s.insert(make_pair(x,y));
		mm[y].insert(x);
		mini[y] = min(mini[y],x);
	}
	int ret = h;
	int y = 1;
	for(int x=1;x<=h;++x){
		while(mm[y].size()>0){
			if( *(mm[y].begin())<=x){
				if(*mm[y].begin() == x){
					ret = min(ret,x);
					break;
				}
				mm[y].erase(mm[y].begin());
			} else {
				break;
			}
		}
		//cout<<x<<" "<<y<<endl;
		if(mm[y].size()>0){
			ret = min(ret, *mm[y].begin() -  1);
		}
		if(y+1<=x && !s.count(make_pair(x,y+1))){
			++y;
		}
	}
	printf("%d\n", ret);

}
int main(){
	//freopen("input.txt","r",stdin);
	solve();
}