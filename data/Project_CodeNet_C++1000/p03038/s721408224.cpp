#include <bits/stdc++.h>
using namespace std;

map<long long,long long> mp;
long long n,m,a,b,c,ans;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		mp[a]++;
	}
	for(int i=0;i<m;i++){
		cin>>b>>c;
		mp[c]+=b;
	}
	map <long long,long long > :: iterator it;
	for(it=--mp.end();;it--){
		ans+=min(n,it->second)*it->first;
		n-=it->second;
		if(n<0) break;
	}
	cout<<ans<<endl;
}