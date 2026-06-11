#include <bits/stdc++.h>
using namespace std;
int child[100005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	int n=s.size();
	if(s[n-1]=='1'){
		cout<<-1;
		return 0;
	}
	if(s[0]=='0'){
		cout<<-1;
		return 0;
	}
	vector<int>v;
	for(int i=0;i<n-1;i++){
		if(s[i]!=s[n-2-i]){
			cout<<-1;
			return 0;
		}
		if(s[i]=='1') v.push_back(i+1);
	}
	v.push_back(n);
	vector<pair<int, int>>edges;
	int cur=2, tmp=1;
	for(int i=0;i<v[0]-1;i++){
		edges.push_back({tmp, cur++});
	}
	for(int i=1;i<v.size();i++){
		edges.push_back({cur, tmp});
		tmp=cur;
		cur++;
		for(int j=0;j<v[i]-v[i-1]-1;j++){
			edges.push_back({tmp, cur++});
		}
	}
	for(auto i:edges){
		cout<<i.first<<" "<<i.second<<'\n';
	}
}