#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	bool f=false;
	ll sum=0;
	cin>>s;
	if(s.length()==1){
		sum=stoi(s);
	}else{
		for(int i=1;i<s.length();i++){
			if(s.substr(i,1)!="9") f=true;
		}
		if(f){
			sum+=stoi(s.substr(0,1))-1;
			sum+=(s.length()-1)*9;
		}else{
			sum+=stoi(s.substr(0,1));
			sum+=(s.length()-1)*9;
		}
	}
	cout<<sum<<endl;
	return 0;
}
