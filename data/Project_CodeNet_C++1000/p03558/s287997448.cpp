#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <cstring>
#include <cmath>
//#include<bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
const int SIZE=100005;

deque<int> que;
int dist[SIZE];

int main(){
	int k;
	cin>>k;
	for(int i=0;i<k;i++) dist[i]=INF;
	dist[1]=1;
	que.push_back(1);
	while(!que.empty()){
		int u=que.front();
		que.pop_front();
		if(dist[(u*10)%k]>dist[u]){
			dist[(u*10)%k]=dist[u];
			que.push_front((u*10)%k);
		}
		if(dist[(u+1)%k]>dist[u]){
			dist[(u+1)%k]=dist[u]+1;
			que.push_back((u+1)%k);
		}
	}
	cout<<dist[0]<<endl;
}
