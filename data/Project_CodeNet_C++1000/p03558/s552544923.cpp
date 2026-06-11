#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=1e9+7,MAXK=1e5+10;
int K;
bool vis[MAXK];
deque<pair<int,int> > dq;
int main(){
	scanf("%d",&K);
	dq.push_front(make_pair(1,1));
	while(dq.size()){
		pair<int,int> cur=dq.front();
		dq.pop_front();
		vis[cur.first]=1;
		if(!cur.first){
			printf("%d",cur.second);
			return 0;
		}
		if(!vis[cur.first*10%K])
			dq.push_front(make_pair(cur.first*10%K,cur.second));
		if(!vis[(cur.first+1)%K])
			dq.push_back(make_pair((cur.first+1)%K,cur.second+1));
	}
	return 0;
}