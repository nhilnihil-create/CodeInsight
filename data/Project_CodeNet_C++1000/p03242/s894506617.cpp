#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++) 
using namespace std;
typedef long long ll;

int main(){
	string s; cin>>s;
	rep(i,s.size()){
		if(s[i]=='1') cout << 9;
		else cout << 1;
	}
	cout << endl;	
}
