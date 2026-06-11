#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int ar[N];
vector<int> lis;
vector<pair<int,int> > ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l,now;
	string s;
	cin>>s;
	n=s.size();
	s=' '+s;
	if(s[n]=='1'){
		cout<<-1;
		return 0;
	}
	if(s[1]=='0'){
		cout<<-1;
		return 0;
	}
	for(i=1;i<n;i++){
		if(s[i]!=s[n-i]){
			cout<<-1;
			return 0;
		}
		if(s[i]=='1'){
			lis.push_back(i);
		}
	}
	now=lis.size()+1;
	for(i=0;i<lis.size();i++){
		ans.push_back({i+1,i+2});
		if(i){
			k=lis[i]-lis[i-1]-1;
		}
		else{
			k=lis[0]-1;
		}
		for(j=1;j<=k;j++){
			now++;
			ans.push_back({i+1,now});
		}
	}
	for(i=0;i<ans.size();i++){
		cout<<ans[i].first<<' '<<ans[i].second<<'\n';
	}
}