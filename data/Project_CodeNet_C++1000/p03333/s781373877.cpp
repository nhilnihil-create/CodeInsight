#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000

int main(){
	
	int N;
	cin>>N;
	priority_queue<pair<int,int>> L;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> R;
	vector<pair<long long,long long>> P(N);
	for(int i=0;i<N;i++){
		cin>>P[i].first>>P[i].second;
		L.emplace(P[i].first,i);
		R.emplace(P[i].second,i);
	}
	
	set<int> used;
	long long ans = 0LL;
	long long now = 0LL;
	
	for(int i=0;true;i++){
		if(L.size()==0&&R.size()==0)break;
		while(L.size()!=0&&used.count(L.top().second))L.pop();
		long long l = Inf;
		if(L.size()!=0){
			l = L.top().first;
			used.insert(L.top().second);
			L.pop();
		}
		while(R.size()!=0&&used.count(R.top().second))R.pop();
		long long r = Inf;
		if(R.size()!=0){
			r = R.top().first;
			used.insert(R.top().second);
			R.pop();
		}
		//cout<<l<<','<<r<<endl;
		if(l!=Inf)ans = max(ans,now+2*l);
		if(r!=Inf)ans = max(ans,now-2*r);
		if(l==Inf||r==Inf)break;
		now += 2*l;
		now -= 2*r;
		ans = max(ans,now);
	}
	
	cout<<ans<<endl;
	

	return 0;
}