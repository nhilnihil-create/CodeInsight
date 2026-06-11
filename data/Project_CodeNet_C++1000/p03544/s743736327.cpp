#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	ll L0=2;	ll L1=1;
	ll Ln;
	if(n==1) {cout<<1<<endl; return 0;}
	rep(i,n-1){
		Ln=L1+L0;
		L0=L1;
		L1=Ln;
	}
	cout<<Ln<<endl;
}