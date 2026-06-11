#include<bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	int g = __gcd(n,m);
	bool ok=true;
	for(int i=0,j=0;i<n;i+=n/g,j+=m/g)
		if(s[i]!=t[j])
			ok=false;
	if(ok)
		cout<<1LL*n*m/g<<endl;
	else
		cout<<-1<<endl;
}
