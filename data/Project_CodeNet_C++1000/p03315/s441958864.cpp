#include <bits/stdc++.h>
using namespace std;

string s;
int ans;

int main(){
	cin>>s;
	
	for(int i=0; i<s.size(); i++){
		if(s[i]=='+') ans++;
		else ans--;
	}
	cout<<ans<<endl;
}
