#include<bits/stdc++.h> 
using namespace std;

#define int long long

const int N = 1e5 + 5, MOD = 1e9 + 7;

int32_t main(){
	
	int n; cin>>n;
	string s; cin>>s;
	int r=0, b=0;
	for(int i=0;i<n;i++){
		if(s[i]=='R') r++;
		else b++;
	}
	if(r>b) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}
 
/*

*/
