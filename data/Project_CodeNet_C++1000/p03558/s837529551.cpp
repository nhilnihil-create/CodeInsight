#include<iostream>
#include<deque>
using namespace std;
const int MOD=10000007;
int dist[100000],k;
deque<int> todo;
int main()
{
	cin>>k;
	for(int i=0;i<k;i++){
		dist[i]=MOD;
	}
	dist[1]=1;
	todo.push_back(1);
	while(todo.size()){
		int u=todo.front();
		todo.pop_front();
		if(dist[(10*u)%k]>dist[u]){
			dist[(10*u)%k]=dist[u];
			todo.push_front(10*u%k);
		}
		if(dist[(u+1)%k]>dist[u]+1){
			dist[(u+1)%k]=dist[u]+1;
			todo.push_back((u+1)%k);
		}
	}
	cout<<dist[0];
	return 0;
} 