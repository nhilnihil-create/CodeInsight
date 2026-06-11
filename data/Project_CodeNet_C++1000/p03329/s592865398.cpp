#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	int n;
	cin>>n;
	vector<int> mon(n+1,-1);

	queue<int> que;
	mon.at(0)=0;
	que.push(0);

	while(!que.empty()){
		int now=que.front();
		que.pop();
		if(now==n){
			cout<<mon.at(now)<<endl;
			return 0;
		}

		int pre=now+1;
		if(pre<=n && mon.at(pre)==-1){
			mon.at(pre)=mon.at(now)+1;
			que.push(pre);
		}

		for(int i=6;now+i<=n;i*=6){
			if(mon.at(now+i)!=-1) continue;

			mon.at(now+i)=mon.at(now)+1;
			que.push(now+i);
		}

		for(int i=9;now+i<=n;i*=9){
			if(mon.at(now+i)!=-1) continue;

			mon.at(now+i)=mon.at(now)+1;
			que.push(now+i);
		}
	}

	return 0;
}
