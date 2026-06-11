#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <deque>
#define mp make_pair
using namespace std;
int k,d[100005];
bool used[100005];
priority_queue <pair<int,int> > pq;
vector <pair<int,int> > ve[100005];
int main(){
	cin>>k;
	for (int i=0;i<k;i++){
		ve[i].push_back(mp((i+1)%k,1));
		ve[i].push_back(mp(i*10%k,0));  
	}
	pq.push(mp(0,1));
	while (!pq.empty()){
		int x=pq.top().second;
		int v=pq.top().first;
		pq.pop();
		if (x==0){
			cout<<-v+1;
			return 0;
		}
		if (used[x]) continue;
		used[x]=true;
		for (int i=0;i<ve[x].size();i++){
			if (!used[ve[x][i].first]){
				pq.push(mp(v-ve[x][i].second,ve[x][i].first));
			}
		}
	}
}