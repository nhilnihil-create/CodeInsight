#include<iostream>
#include<iomanip>
#include<functional>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<set>
#include<queue>
#include<cmath>

using namespace std;
#define LL long long

int N,K,ans=1e9;
vector<int>p,m;

int main() {
	cin>>N>>K;
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		if(x==0)K--;
		else if(x<0)m.push_back(x);
		else p.push_back(x);
	}
	if(K==0){
		cout<<0<<endl;
		return 0;
	}
	reverse(m.begin(),m.end());
	for(int i=0;i<=min((int)m.size(),K);i++){
		int mc=i,pc=K-i;
		if(mc>(int)m.size()||pc>(int)p.size())continue;
		int t1=1e9,t2=1e9;
		if(mc==0)ans=min(ans,p[K-1]);
		else{
			t1=-m[mc-1];
			t2=-m[mc-1]*2;
		}
		if(pc==0)ans=min(ans,-m[K-1]);
		else{
			t1+=p[pc-1]*2;
			t2+=p[pc-1];
		}
		ans=min({ans,t1,t2});
	}
	cout<<ans<<endl;


	return 0;
}

