#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
bool used[100005];
priority_queue<P1>que[2];
int n;
int L[100005],R[100005];
ll ans,ans2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&L[i],&R[i]);
		que[0].push(mp(-R[i],mp(L[i],i)));
		que[1].push(mp(L[i],mp(R[i],i)));
	}
	//0 first
	int zan = n;
	int cur = 0;
	while(1){
		while(!que[0].empty() && used[que[0].top().sc.sc]) que[0].pop();
		used[que[0].top().sc.sc] = 1;
		zan--;
		int x = que[0].top().sc.fi,y = -(que[0].top().fi);
		if(cur<x){
			ans+=x-cur;
			cur=x;
		}
		else if(y<cur){
			ans+=cur-y;
			cur=y;
		}
		que[0].pop();
		if(!zan) break;
		while(!que[1].empty() && used[que[1].top().sc.sc]) que[1].pop();
		used[que[1].top().sc.sc] = 1;
		zan--;
		x = que[1].top().fi,y = que[1].top().sc.fi;
		if(cur<x){
			ans+=x-cur;
			cur=x;
		}
		else if(y<cur){
			ans+=cur-y;
			cur=y;
		}
		que[1].pop();
		if(!zan) break;
	}
	ans += abs(cur);
	while(que[0].size()) que[0].pop();
	while(que[1].size()) que[1].pop();
	
	for(int i=1;i<=n;i++){
		que[0].push(mp(-R[i],mp(L[i],i)));
		que[1].push(mp(L[i],mp(R[i],i)));
	}
	//1 first
	zan = n;
	cur = 0;
	memset(used,0,sizeof(used));
	while(1){
		while(!que[1].empty() && used[que[1].top().sc.sc]) que[1].pop();
		used[que[1].top().sc.sc] = 1;
		zan--;
		int x = que[1].top().fi,y = que[1].top().sc.fi;
		if(cur<x){
			ans2+=x-cur;
			cur=x;
		}
		else if(y<cur){
			ans2+=cur-y;
			cur=y;
		}
		que[1].pop();
		if(!zan) break;
		while(!que[0].empty() && used[que[0].top().sc.sc]) que[0].pop();
		used[que[0].top().sc.sc] = 1;
		zan--;
		x = que[0].top().sc.fi,y = -(que[0].top().fi);
		if(cur<x){
			ans2+=x-cur;
			cur=x;
		}
		else if(y<cur){
			ans2+=cur-y;
			cur=y;
		}
		que[0].pop();
		if(!zan) break;
	}
	ans2 += abs(cur);
	while(que[0].size()) que[0].pop();
	while(que[1].size()) que[1].pop();
	
	cout<<max(ans,ans2)<<endl;
}