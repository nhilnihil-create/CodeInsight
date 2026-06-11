
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const ll INF=1000000007LL;
typedef pair<int,int> P;
bool c[100001]={};
int main() {
	int k;
	cin>>k;
	int s=1;
	deque<P> que;
	que.push_front(P(0,1%k));
	int ans;
	while(!que.empty()){
		P p=que.front();que.pop_front();
		int d=p.first,n=p.second;
		if(c[n])continue;
		c[n]=true;
		if(n==0){
			ans=d+1;
			break;
		}
		que.push_front(P(d,(n*10)%k));
		que.push_back(P(d+1,(n+1)%k));
	}
	cout<<ans<<endl;
	return 0;
}
