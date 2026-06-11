#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int,int> pa;
#define x first
#define y second
vector<pa> e;
int main(){
	int h,w,n;
	cin>>h>>w>>n;
	int i,x,y,ans=h;
	while(n--){
		scanf("%d%d",&x,&y);
		if(x>=y)e.pb({x,y});
	}
	sort(e.begin(),e.end());
	x=1,y=1;
	for(auto c:e){
		if(c.x-x>c.y-y){ans=c.x-1;break;}
		else if(c.x-x==c.y-y)x=c.x,y=c.y-1;
	}
	cout<<ans<<endl;
}