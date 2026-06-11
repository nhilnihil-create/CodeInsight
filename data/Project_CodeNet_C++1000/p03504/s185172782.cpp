#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
priority_queue<int,vector<int>,greater<int> >pq[33];
priority_queue<pii,vector<pii>,greater<pii> >program;
int main(){
	int n,c;
	cin>>n>>c;
	for(int i=0; i<n; i++){
		int s,t,ch;
		cin>>s>>t>>ch;
		program.push(make_pair(pi(s,t),ch));
	}
	while(!program.empty()){
		int start = program.top().first.first;
		int fin = program.top().first.second;
		int channel = program.top().second;
		program.pop();
		if(!pq[channel].empty() && pq[channel].top()<=start){
			pq[channel].pop();
			pq[channel].push(fin);
			continue;
		}
		bool found = false;
		for(int i=1; i<=c; i++){
			if(pq[i].empty()) continue;
			if(pq[i].top()<start){
				pq[i].pop();
				pq[channel].push(fin);
				found = true;
				break;
			}
		}
		if(!found) pq[channel].push(fin);
	}
	int ans = 0;
	for(int i=1; i<=c; i++) ans+=pq[i].size();
	cout<<ans;
}