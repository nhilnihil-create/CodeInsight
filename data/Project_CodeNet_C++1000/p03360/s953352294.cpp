#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b,c,k; cin>>a>>b>>c>>k;
	int mx=max(a,max(b,c));
	int ans=mx;
	rep(i,k) ans*=2;
	cout<<ans+a+b+c-mx<<endl;
}