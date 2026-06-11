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
deque <int> que;
vector <pair<int,int> > ve[100005];
int main(){
	cin>>k;
	for (int i=0;i<k;i++){
		ve[i].push_back(mp((i+1)%k,1));
		ve[i].push_back(mp(i*10%k,0));  
	}
	que.push_back(1); 
	d[1]=1;
	while (!que.empty()){
		int x=que.front();
		que.pop_front();
		if (used[x]) continue;
		used[x]=true;
		for (int i=0;i<ve[x].size();i++){
			if (!used[ve[x][i].first]){
				if (ve[x][i].second==0){
					que.push_front(ve[x][i].first);
					d[ve[x][i].first]=d[x]; 
				}else{
					que.push_back(ve[x][i].first);
					d[ve[x][i].first]=d[x]+1; 
				}
			}
		}
	}
	cout<<d[0];
	return 0;
}