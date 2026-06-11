#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	int ans=1<<30;
	cin>>s;
	for(int i=1; i<s.length(); i++)
		if(s[i-1]!=s[i])
			ans=min(ans,max(i,int(s.length())-i));
	cout<<min(ans,int(s.length()))<<'\n';
	return 0;
}