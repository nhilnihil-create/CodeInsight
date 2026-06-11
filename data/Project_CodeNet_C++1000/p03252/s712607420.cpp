#include<bits/stdc++.h>
using namespace std;
set<int>pattern[26];

int main(){
	string s,t;
	cin>>s>>t;
	for(int i=0; s[i]; i++){
		pattern[(int)(s[i]-'a')].insert(i);
	}
	for(int i=0; i<26; i++){
		if(pattern[i].size()){
			vector<int>arr;
			for(set<int>::iterator it = pattern[i].begin(); it!=pattern[i].end(); it++){
				arr.push_back(*it);
			}
			for(int j=1; j<arr.size(); j++){
				if(t[arr[0]]!=t[arr[j]]){
					cout<<"No";
					return 0;
				}
			}
		}
		pattern[i].clear();
	}
	
	for(int i=0; t[i]; i++){
		pattern[(int)(t[i]-'a')].insert(i);
	}
	for(int i=0; i<26; i++){
		if(pattern[i].size()){
			vector<int>arr;
			for(set<int>::iterator it = pattern[i].begin(); it!=pattern[i].end(); it++){
				arr.push_back(*it);
			}
			for(int j=1; j<arr.size(); j++){
				if(s[arr[0]]!=s[arr[j]]){
					cout<<"No";
					return 0;
				}
			}
		}
		pattern[i].clear();
	}
	cout<<"Yes";
}