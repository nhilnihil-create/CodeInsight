#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
  	cin>>s;
  	int cnt = count(s.begin(),s.end(),'x');
  	if(cnt>=8) cout<<"NO";
  	else cout<<"YES";
}