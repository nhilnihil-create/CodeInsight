#include<bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	cin>>s;
	transform(s.begin(), s.end(), s.begin(), [](char c){
			return c=='1'?'9':'1';});
	cout<<s<<'\n';
	return 0;
}
