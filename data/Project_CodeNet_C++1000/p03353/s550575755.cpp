#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int n,k;
	cin>>s>>k;
	set<string>ss;
	n = s.length();
	for(int i=0; s[i]; i++){
		for(int j=i; s[j]; j++){
			int len = j-i+1;
			if(len>k) break; 
			ss.insert(s.substr(i,len));
		}
	}
	set<string>::iterator it;
	int counter = 0;
	for(it = ss.begin(); it!=ss.end(); it++){
		counter++;
		if(counter==k){
			cout<<*it;
			return 0;
		}
	}
}