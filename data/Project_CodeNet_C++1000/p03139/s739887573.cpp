#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,a,b; cin>>n>>a>>b;
	int c=min(a,b);
	int m=a+b-n;
	if(m>0) cout<<c<<" "<<m<<endl;
	else cout<<c<<" "<<0<<endl;
}