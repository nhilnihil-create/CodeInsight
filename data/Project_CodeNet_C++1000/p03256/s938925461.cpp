#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
//
const int inf=1e9+7;//0x3f
//
int N,M;
string S;
vector<int> V[200001];
bool used[200001];
int A[200001],B[200001];
int main(){
	cin>>N>>M>>S;
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		V[a].push_back(b);
		V[b].push_back(a);
		if(S[a]=='A'){
			A[b]++;
		}else{
			B[b]++;
		}
		if(S[b]=='A'){
			A[a]++;
		}else{
			B[a]++;
		}
	}
	queue<int> que;
	for(int i=0;i<N;i++){
		if(A[i]==0||B[i]==0){
			que.push(i);
			used[i]=true;
		}
	}
	int ans=0;
	while(!que.empty()){
		int v=que.front();
		que.pop();
		ans++;
		for(int i=0;i<V[v].size();i++){
			int t=V[v][i];
			if(!used[t]){
				if(S[v]=='A'){
					A[t]--;
				}else{
					B[t]--;
				}
				if(A[t]==0||B[t]==0){
					used[t]=true;
					que.push(t);
				}
			}
		}
	}
	if(ans<N){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}