#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000
bool f = false;
map<pair<string,string>,int> get(string S){
	int N = S.size();
	map<pair<string,string>,int> mp;
	for(int i=0;i<(1<<N);i++){
		string s="",t="";
		for(int j=0;j<N;j++){
			if((i>>j)&1)s+=S[j];
			else t+=S[j];
		}
		reverse(t.begin(),t.end());
		if(f)swap(s,t);
		mp[make_pair(s,t)]++;
	}
	f=true;
	return mp;
}

int main(){
	
	int N;
	cin>>N;
	
	string S;
	cin>>S;
	
	map<pair<string,string>,int> mp0 = get(S.substr(0,N)),mp1 = get(S.substr(N));
	
	long long ans = 0;

	for(auto a:mp0){
		ans += (long long)a.second * mp1[a.first];
	}
	cout<<ans<<endl;
	
	return 0;
}