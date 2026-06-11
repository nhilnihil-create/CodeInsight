#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	string s; cin>>s;
	if(s.substr(0,4)<"2019"){
		cout <<"Heisei" <<endl;
	}
	else if(s.substr(0,4)>"2019"){
		cout <<"TBD"<<endl;
	}
	else if(s.substr(5,2)<="04"){
		cout <<"Heisei" <<endl;
	}
	else cout <<"TBD"<<endl;
	
}