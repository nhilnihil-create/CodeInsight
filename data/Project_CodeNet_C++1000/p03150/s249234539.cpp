#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		for(int j=i;j<s.size();j++){
			if(s.substr(0,i)+s.substr(j+1)=="keyence"){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	if(s=="keyence"){
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
	return 0;
}