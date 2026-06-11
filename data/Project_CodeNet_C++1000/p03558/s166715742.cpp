#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>

using namespace std;

int d[100005];
int K;

void solve(){
	fill(d,d+K,1<<30);
	d[1]=1;
	deque<int>que;
	que.push_front(1);

	while(!que.empty()){
		int v=que.front();que.pop_front();
		int to=(v+1)%K;
		if(d[to]>d[v]+1){
			d[to]=d[v]+1;
			que.push_front(to);
		}
		to=(v*10)%K;
		if(d[to]>d[v]){
			d[to]=d[v];
			que.push_back(to);
		}
	}

	cout<<d[0]<<endl;

}

int main(){


	scanf("%d",&K);

	solve();

	return 0;
}