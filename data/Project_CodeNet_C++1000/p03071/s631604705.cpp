#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++) 
using namespace std;
typedef long long ll;

int main(){
	int a,b; cin>>a>>b;
	int ans=0;
	if(a>b){ans+=a; a-=1;}
	else {ans+=b; b-=1;}
	if(a>b){ans+=a; a-=1;}
	else {ans+=b; b-=1;}
	cout << ans << endl;
}