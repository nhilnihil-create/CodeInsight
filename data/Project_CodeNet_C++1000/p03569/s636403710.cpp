#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	string s;
	cin>>s;
	
	string t = "";
	
	for(int i=0;i<s.size();i++){
		if(s[i]!='x'){
			t += s[i];
		}
	}
	
	string tr = t;
	reverse(tr.begin(),tr.end());
	
	if(tr!=t){
		cout<<-1<<endl;
		return 0;
	}
	
	vector<int> cnt(1,0);
	
	for(int i=0;i<s.size();i++){
		if(s[i]=='x'){
			cnt.back()++;
		}
		else{
			cnt.push_back(0);
		}
	}
	
	int ans = 0;
	
	for(int i=0;i<cnt.size();i++){
		int m = max(cnt[i],cnt[cnt.size()-1-i]);
		ans += m-cnt[i];
		ans += m-cnt[cnt.size()-1-i];
		cnt[i] = m;
		cnt[cnt.size()-1-i] = m;
	}
	
	cout<<ans<<endl;
	
	return 0;
}