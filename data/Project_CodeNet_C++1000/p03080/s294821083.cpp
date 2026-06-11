#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	string s; cin>>s;
	int r=0, b=0;
	rep(i,n){
		if(s[i]=='R') r++;
		else b++;
	}
	cout<<(r>b?"Yes":"No")<<endl;
}