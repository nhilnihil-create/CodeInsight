#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b,x; cin>>a>>b>>x;
	if(a>x) cout<<"NO"<<endl;
	else if(a==x||a+b>=x) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}