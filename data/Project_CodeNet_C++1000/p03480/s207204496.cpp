#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	int len=s.size(),ans=s.size();
	for(int i=0;s[i+1];i++)
		if(s[i]!=s[i+1])
			ans=min(ans,max(i+1,len-i-1));
	cout<<ans;
	return 0;
}