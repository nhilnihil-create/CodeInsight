#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using ll = long long;

using namespace std;

ll mod=1e9+7;


int main() {
	string s,t;
	cin>>s>>t;
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	bool ok=false;
	for(int i=0;i<s.size();i++){
		int counter=0;
		for(int j=0;j<t.size();j++){
			if(i+j>=s.size())continue;
			if(t[j]==s[i+j]||s[i+j]=='?'){
				counter++;
			}
		}
		if(counter==t.size()){
			for(int j=0;j<t.size();j++){
				s[i+j]=t[j];
			}
			ok=true;
			break;
		}
	}
	if(ok){
		for(int i=0;i<s.size();i++){
			if(s[i]=='?')s[i]='a';
		}
		reverse(s.begin(),s.end());
		cout<<s<<endl;
	}else{
		cout<<"UNRESTORABLE"<<endl;
	}
	return 0;
}