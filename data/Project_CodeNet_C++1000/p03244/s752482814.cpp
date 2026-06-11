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

int n,v[111111],ans;
map<int,int>odd,even;
vector<pair<int,int>>o,e;

int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(i&1)even[v[i]]++;
		else odd[v[i]]++;
	}
	for(auto i:odd)o.push_back({i.second,i.first});
	for(auto i:even)e.push_back({i.second,i.first});
	sort(o.rbegin(),o.rend());
	sort(e.rbegin(),e.rend());
	o.push_back({0,0});
	e.push_back({0,0});
	if(o[0].second!=e[0].second)ans=n-o[0].first-e[0].first;
	else ans=n-max(e[0].first+o[1].first,e[1].first+o[0].first);
	cout<<ans<<endl;
	return 0;
}

