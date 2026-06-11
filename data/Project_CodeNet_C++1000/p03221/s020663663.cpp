#include<bits/stdc++.h>
	using namespace std;
	typedef pair<int,int> pi;
	vector<pi>city;
	map<pi,string>hasher;
	vector<int>establish[100005];
	
	int main(){
		int n,m;
		cin>>n>>m;
		for(int i=0; i<m; i++){
			int a,b;
			cin>>a>>b;
			city.push_back(pi(a,b));
			establish[a].push_back(b);
		}
		for(int i=1; i<=n; i++) sort(establish[i].begin(),establish[i].end());
		for(int i=1; i<=n; i++){
			if(establish[i].size()){
				for(int j=0; j<establish[i].size(); j++){
					int first_id = i;
					int second_id = j+1;
					string s = "000000000000";
					int p = 5;
					while(first_id){
						s[p--] = (first_id%10+'0');
						first_id/=10;
					}
					p = 11;
					while(second_id){
						s[p--] = (second_id%10+'0');
						second_id/=10;
					}
					hasher.insert(make_pair(pi(i,establish[i][j]),s));
				}
			}
		}
		for(int i=0; i<city.size(); i++){
			cout<<hasher.find(pi(city[i].first,city[i].second))->second<<'\n';
		}
	}