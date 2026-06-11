#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

long long n,m;
vector<int> edge[100005];
int color[100005];

queue<pair<int, pair<int,int> > > q;

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	q.push(make_pair(0,make_pair(1,-1)));

	bool two = true;

	while(!q.empty()){
		pair<int, pair<int,int> > now = q.front();
		q.pop();
		int nowp = now.first;
		int nowcol = now.second.first;
		int prevp = now.second.second;
		//cout<<nowp<<" "<<nowcol<<" "<<prevp<<endl;
		if(color[nowp] != 0) continue;
		color[nowp] = nowcol;
		for(int i=0;i<edge[nowp].size();i++){
			if(edge[nowp][i] == prevp){
				continue;
			}
			if(color[edge[nowp][i]] != 0){
				if(color[edge[nowp][i]] == (-1*nowcol)) continue;
				else {
					two = false;
				}
			}
			q.push(make_pair(edge[nowp][i],make_pair(-1*nowcol,nowp)));
		}
	}

	ans:
	if(two){
		long long s=0;
		long long t=0;
		for(int i=0;i<n;i++){
			if(color[i]== 1)s++;
			else t++;
		}
		cout<<(s*t-m)<<endl;
	} else {
		cout<<(n*(n-1)/2-m)<<endl;
	}

	return 0;

}
