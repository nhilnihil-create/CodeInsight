#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;
int n;
vector<int> vec;

bool chk(int ans){
	map<int,int> mp;
	for(int i=1;i<vec.size();++i)
		if(vec[i-1]>=vec[i]){
			while(!mp.empty()&&mp.rend()->first>vec[i])
				mp.erase(prev(mp.end()));
			int pos=vec[i];
			while(mp[pos]==ans-1)
				mp.erase(mp.find(pos)),--pos;
			++mp[pos];
		}
	return mp.begin()->first>0;
}

int main(){
	cin>>n;
	for(int i=1,a;i<=n;++i){
		cin>>a;
		vec.push_back(a);
	}
	{
		bool ans1=true;
		for(int i=1;i<vec.size();++i)
			if(vec[i-1]>=vec[i])
				ans1=false;
		if(ans1){
			puts("1");
			return 0;
		}
	}
	int l=2,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(chk(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}