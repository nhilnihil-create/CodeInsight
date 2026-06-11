#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n =0;
	string s;
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if( s[i] == '+') n++;
		else n--;
	}
	cout<<n;
	
	return 0;
}
