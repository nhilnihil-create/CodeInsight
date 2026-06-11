#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++) 
using namespace std;
typedef long long ll;

int main(){
	string s; cin>>s;
	int ans=0;
	rep(i,4){
		if(s[i]=='+') ans++;
		else ans--;
	}
	cout << ans << endl;	
}