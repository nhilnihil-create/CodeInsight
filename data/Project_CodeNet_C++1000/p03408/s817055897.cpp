#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
 
int main(){
	int n,m,ans=0;
	cin>>n;
	string s[n],ser;
	for(int i=0;i<n;i++)cin>>s[i];
	cin>>m;
	string t[m];
	for(int j=0;j<m;j++)cin>>t[j];

	for(int i=0;i<n;i++){
		int cnt=0;
		string ser=s[i];
		for(int j=0;j<n;j++){
			if(ser==s[j])cnt++;
		}
		for(int j=0;j<m;j++){
			if(ser==t[j])cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
}