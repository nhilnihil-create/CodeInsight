#include<iostream>
#include<string>
using namespace std;
string s;
int n;
int x,y;
int ans=0;
int main(){
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='0')x++;
		else y++;
	}
	if(x==y)ans=x*2;
	else ans=min(x,y)*2;
	cout<<ans<<endl;
	return 0;
}