#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18)
#define all(v) v.begin(),v.end()
using namespace std;

template<class T> inline void chmax(T& a, T b) { a = std::max(a, b); }
template<class T> inline void chmin(T& a, T b) { a = std::min(a, b); }

int n;
int dis[1000005];
deque<P>que;
signed main() {
	cin>>n;
	rep(i,n)dis[i]=inf;
	dis[1]=1;
	que.push_back({1,1});
	while(!que.empty()){
		P p=que.front();que.pop_front();
		if(dis[p.second]<p.first)continue;
		if(p.second%10!=9){
			if(dis[(p.second+1)%n]>p.first+1){
				dis[(p.second+1)%n]=p.first+1;
				que.push_back({p.first+1,(p.second+1)%n});
			}
		}
		if(dis[(p.second*10)%n]>p.first){
			dis[(p.second*10)%n]=p.first;
			que.push_front({p.first,(p.second*10)%n});
		}
	}
	cout<<dis[0]<<endl;
}
