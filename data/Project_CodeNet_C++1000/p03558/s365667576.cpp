#include <iostream>
#include <queue>
#define mp make_pair
using namespace std;
deque<pair<int,int> > q;bool vis[100005];int k,ans=0; 
int main(){
	cin>>k;q.push_front(mp(1,1));while(!q.empty()){pair<int,int> x=q.front();q.pop_front();if(x.first==0){cout<<ans+x.second;return 0;}if(vis[x.first]){continue;}vis[x.first]=1;q.push_back(mp((x.first+1)%k,x.second+1));q.push_front(mp((x.first*10%k),x.second));}return 0;
}