#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int dist=800;
	for(int i=0;i<s.size()-2;i++){
		int x=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
		dist=min(dist,abs(753-x));
	}
	cout<<dist;
	return 0;
}
