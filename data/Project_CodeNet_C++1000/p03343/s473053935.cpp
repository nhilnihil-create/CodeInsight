#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000005


int main(){
	
	int N,K,Q;
	cin>>N>>K>>Q;
	
	vector<pair<int,int>> P;
	
	vector<int> A(N);
	for(int i=0;i<N;i++){
		cin>>A[i];
		P.emplace_back(A[i],i);
	}
	
	sort(P.begin(),P.end());
	int ans = Inf;
	for(int i=0;i<=N;i++){
		priority_queue<int,vector<int>,greater<int>> QQ;
		int now = 0;
		while(true){
			if(now>=N)break;
			priority_queue<int,vector<int>,greater<int>> q;
			while(now!=N&&A[now]!=Inf){
				q.push(A[now]);
				now++;
			}
			while(q.size()>=K){
				QQ.push(q.top());
				q.pop();
			}
			now++;
		}
		if(QQ.size()<Q)break;
		int Y = QQ.top();
		for(int j=0;j<Q-1;j++)QQ.pop();
		int X = QQ.top();
		ans = min(ans,X-Y);
		if(i!=N){
			A[P[i].second]=Inf;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
	
}
