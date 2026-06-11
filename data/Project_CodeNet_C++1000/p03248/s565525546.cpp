#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int n=s.size();
	bool flag=false;
	
	if(s[0]=='0')flag=true;
	if(s[n-1]=='1')flag=true;
	for(int i=1;i<n-1;i++){
		int j=n-2-i;
		if(s[i]!=s[j])flag=true;
	}
	
	if(flag){
		cout << "-1" << endl;
		return 0;
	}
	
	s[n-1]='1';
	int min1=n-1;
	for(int i=n-2;i>=0;i--){
		cout << i+1 << " " << min1+1 << endl;
		if(s[i]=='1')min1=i;
	}
	return 0;
}