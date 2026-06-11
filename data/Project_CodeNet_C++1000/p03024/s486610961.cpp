#include <bits/stdc++.h>
using namespace std; 
string s;
int main() { 
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='x')cnt++;
	}
	if(cnt>=8)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
    return 0; 
}