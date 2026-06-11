#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using ll = long long;

using namespace std;

ll mod=1e9+7;


int main() {
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>island(m,pair<int,int>(n-1,0));
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		island[i].second=a;
		island[i].first=b;
	}
	int tmp=-1;
	int ans=0;
	sort(island.begin(),island.end());
	for(int i=0;i<m;i++){
		if(tmp>island[i].second){
			continue;
		}
		tmp=island[i].first;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}