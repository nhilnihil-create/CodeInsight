#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>> graph(111111);
long long ans;
int b=0,w=0;
vector<int> bi(111111,-1);

bool BFS(){
	queue<int> que;
	que.push(0);
	bi[0]=0;
	while(!que.empty()){
		int f=que.front();
		que.pop();
		if(bi[f]==0)b++;
		else w++;
		for(auto t:graph[f]){
			if(bi[t]==-1){
				bi[t]=(bi[f]+1)%2;
				que.push(t);
			}
			else if(bi[t]==bi[f])return false;
		}
	}
	return true;
}

int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int A,B;
		cin >> A >> B;
		A--;
		B--;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	
	if(BFS())ans=(long long)b*w-M;
	else ans=((long long)N*N-N)/2-M;
	
	cout << ans << endl;
	return 0;
}