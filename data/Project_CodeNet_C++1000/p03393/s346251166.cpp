#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INF = 1e6+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main(){
	
	string s;
	cin >> s;
	vector<int> check(26,0);
	for(int i=0;i<s.size();i++){
		check[s[i]-'a']++;
	}
	
	bool all=true;
	int first=0;
	for(int i=0;i<26;i++){
		if(check[i]==0){
			first=i;
			all=false;
			break;
		}
	}
	
	if(!all){
		s+='a'+first;
		cout << s << endl;
		return 0;
	}
	
	string t=s;
	vector<string> v;
	if(all){
		if(t=="zyxwvutsrqponmlkjihgfedcba"){
			cout << -1 << endl;
			return 0;
		}else{
			do{
				v.push_back(t);
				if(v.size()==2)break;
			}while(next_permutation(t.begin(),t.end()));
		}
	}
	//cout << v[1] << endl;	
	string ans=v[1];
	for(int i=0;i<s.size();i++){
		if(s[i]==ans[i]){
			continue;
		}else{
			ans.erase(i+1,ans.size()-i-1);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
