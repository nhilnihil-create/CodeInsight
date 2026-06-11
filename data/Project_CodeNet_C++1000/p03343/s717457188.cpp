#include<bits/stdc++.h>
using namespace std;
int n,k,Q,a[2005],ans=1e9;
priority_queue<int>que;
vector<int>E;
void update(){
	while(!que.empty()){
		if(que.size()>=k)E.push_back(-que.top());
		que.pop();
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&Q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int Min=a[i];
		for(int j=1;j<=n;j++){
			if(a[j]>=Min)que.push(-a[j]);
			else update();
		}
		update();
		if(E.size()>=1)sort(E.begin(),E.end());
		if(E.size()>=Q&&E[0]==Min)ans=min(ans,E[Q-1]-Min);
		E.clear();
	}
	printf("%d",ans);
	return 0;
}