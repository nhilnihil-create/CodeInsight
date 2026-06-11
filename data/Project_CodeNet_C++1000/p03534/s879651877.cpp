#include "bits/stdc++.h"
using namespace std;

int main(){
	string s;
	cin>>s;
	
	map<char,int> mp;
	for(int i=0;i<s.size();i++){
		mp[s[i]]++;
	}
	
	if(max(mp['a'],max(mp['b'],mp['c']))-min(mp['a'],min(mp['b'],mp['c']))<=1){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}