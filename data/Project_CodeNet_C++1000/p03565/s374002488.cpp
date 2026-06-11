#include<bits/stdc++.h>
using namespace std;
string s,t;
vector<int>pos;
bool check(int start){
	for(int i=0; i<t.length(); i++){
		int s_curr = start+i;
		if(s[s_curr]=='?') continue;
		else{
			if(s[s_curr]!=t[i]) return false; 
		}
	}
	return true;
}
void restore(int start){
	for(int i=0; i<t.length(); i++){
		s[start+i] = t[i];
	}
}
int main(){
	cin>>s>>t;
	int fin = s.length()-t.length();
	for(int i=0; i<=fin; i++){
		if(check(i)) pos.push_back(i);
	}
	if(pos.size()==0) cout<<"UNRESTORABLE";
	else{
		restore(*pos.rbegin());
		for(int i=0; s[i]; i++){
			if(s[i]=='?') cout<<'a';
			else cout<<s[i];
		}
	}
}