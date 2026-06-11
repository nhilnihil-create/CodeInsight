#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
 
int main(){
	
	int n, k; cin>>n>>k;
	string s; cin>>s;
	vector<pair<int,int>> a(1,{1,0});
	
	for(auto i:s){
		if(a.back().first==i-'0') a.back().second++;
		else a.push_back({i-'0',1});
	}
	if(a.back().first==0) a.push_back({1,0});
	deque<int> q;
	for(auto i:a) q.push_back(i.second);
	int ans{}, sum{}, cnt{};
	for(int i=0; i<a.size(); i++){
		if(cnt<k){
			if(a.at(i).first==1){
				sum += a.at(i).second;
			}
			else{
				sum += a.at(i).second;
				cnt++;
			}
		}
		else{
			if(a.at(i).first==1){
				sum += a.at(i).second;
			}
			else{
				sum -= q.front();
				q.pop_front();
				sum -= q.front();
				q.pop_front();
				sum += a.at(i).second;
			}
		}
		ans = max(ans,sum);
	}
	cout << ans << endl;
	
}
