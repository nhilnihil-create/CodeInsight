#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

bool is_valid(string s){
	if(s[0]=='0'||s.back()=='1')return false;
	s.insert(s.begin(),'0');
	string t(s.rbegin(),s.rend());
	if(s!=t)return false;
	
	for(int i=0;true;i++){
		if(s.size()<1+i)break;
		if(s[i]!=s[s.size()-1-i])return false;
	}
	return true;
}

int main(){
	
	string s;
	cin>>s;
	
	if(!is_valid(s)){
		cout<<-1<<endl;
		return 0;
	}
	
	int last = 0;
	vector<pair<int,int>> ans;
	
	for(int i=0;i<s.size()-1;i++){
		if(s[i]=='1'){
			ans.emplace_back(last,i+1);
			last = i+1;
		}
		else{
			ans.emplace_back(last,i+1);
		}
	}
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first+1<<' '<<ans[i].second+1<<endl;
	}
	
	return 0;
}