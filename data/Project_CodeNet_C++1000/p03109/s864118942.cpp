#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		string s;
		cin>>s;
		if( s[5]=='0' && s[6]<='4') cout<<"Heisei";
		else cout<<"TBD";
		return 0;
}
