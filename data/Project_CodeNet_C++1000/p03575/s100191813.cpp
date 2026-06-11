#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> kankei(n+1);
	vector<pair<int,int>> p(m);

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;

		p.at(i)=make_pair(a,b);
		kankei.at(a).push_back(b);
		kankei.at(b).push_back(a);
	}

	int ans=0;

	for(auto at:p){
		int a=at.first;
		int b=at.second;

		vector<bool> been(n+1,false);
		int cnt=0;
		stack<int> que;
		been.at(1)=true;
		que.push(1);

		while(!que.empty()){
			int now=que.top();
			que.pop();
			cnt++;

			for(auto next:kankei.at(now)){
				if(been.at(next)) continue;
				if((now==a && next==b) || (now==b && next==a)) continue;

				been.at(next)=true;
				que.push(next);
			}
		}

		if(cnt<n) ans++;
	}

	cout<<ans<<endl;

	return 0;
}
