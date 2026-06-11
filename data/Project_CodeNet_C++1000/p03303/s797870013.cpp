#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s,ans="";
	int w;
	cin>>s>>w;
	for(int i=0;i<s.length();i++){
		if(i%w==0){
			ans+=s.substr(i,1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
