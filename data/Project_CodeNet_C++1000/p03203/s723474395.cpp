#include "bits/stdc++.h"
using namespace std;
typedef long long lint;
#define MAXN 200010
#define rep(i,n) for(int i=0;i<(n);++i)

vector<int> ma[MAXN];

int main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);

	int h,w,n;cin>>h>>w>>n;
	int x,y;
	rep(i,n){
		cin>>x>>y;--x;--y;
		if(x==1&&y==0){
			cout<<1<<endl;getchar();getchar();return 0;
		}
		ma[x].push_back(y);
	}x=0,y=0;
	rep(j,h){
		++y;
		bool R_movable=1;
		for(int &i:ma[y]){
			if(i<=x){
				cout<<y<<endl;
				getchar();
				getchar();return 0;
			}if(i==x+1){
				R_movable=0;
			}
		}if(R_movable){
			++x;
		}
	}cout<<h<<endl;
	getchar();
	getchar();
	return 0;
}