#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;

int main(){
	int n,ans=0;
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		mp[a]++;
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		if((it->second)<(it->first)) ans+=it->second;
		else ans+=(it->second)-(it->first);
	}
	cout<<ans<<endl;
	return 0;
}