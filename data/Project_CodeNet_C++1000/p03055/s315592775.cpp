#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>

using namespace std;

#define rip(i, n, s) for (int i = (s);i < ( int )( n ); i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> da(n);
	int x,y;
	rip(i,n-1,0){
		cin >> x >> y;
		x--;y--;
		da[x].push_back(y);
		da[y].push_back(x);
	}
	queue<int> q;
	vector<int> dis(n,-1);
	dis[0]=0;
	q.push(0);
	int now;
	while(!q.empty()){
		now=q.front();
		q.pop();
		for(auto i:da[now]){
			if(dis[i]<0){
				dis[i]=dis[now]+1;
				q.push(i);
			}
		}
	}
	rip(i,n,0){
		dis[i]=-1;
	}
	dis[now]=0;
	q.push(now);

	while(!q.empty()){
		now=q.front();
		q.pop();
		for(auto i:da[now]){
			if(dis[i]<0){
				dis[i]=dis[now]+1;
				q.push(i);
			}
		}
	}
	if(dis[now]%3==1){
		cout << "Second" << endl;
	}
	else{
		cout << "First" << endl;
	}
}
