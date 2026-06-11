#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int k;
deque<pair<int,int> > q;
bool used[100010];

int main() {
	cin>>k;
	
	q.push_back({1,1});
	while(!q.empty()) {
		pair<int,int> x=q.front();q.pop_front();
		if(!x.first) {cout<<x.second;return 0;}
		
		if(!used[x.first]) {
			used[x.first]=1;
			q.push_front({(x.first*10)%k,x.second});
			q.push_back({x.first+1,x.second+1});
		}
	}
	
	return 0;
}
