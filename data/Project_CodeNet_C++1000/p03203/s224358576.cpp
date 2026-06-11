#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N=200005;
int W,H,n,x,y;
set<int > S[N];
map<pair<int ,int>  ,int> Map;
int main(){
	scanf("%d%d%d",&W,&H,&n);
	while (n--){
		scanf("%d%d",&x,&y);
		S[y].insert(x);
		Map[mp(x,y)]=1;
	}
	for (int i=1;i<=H;i++)S[i].insert(W+1);
	x=1;y=1;int ans=*S[x].upper_bound(1);
	while (1){
		if (x==W||Map.count(mp(x+1,y)))break;
		x++;
		if (y+1<=H&&!Map.count(mp(x,y+1)))y++;
		ans=min(ans,*S[y].upper_bound(x));
	}
	printf("%d\n",ans-1);
}