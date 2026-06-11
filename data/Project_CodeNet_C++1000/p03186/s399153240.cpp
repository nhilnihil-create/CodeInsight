#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;cin>>a>>b>>c;
  	int q = b+c;
	int ans = 0;
  	ans += 2*min(b,c);
  	//cout<<ans<<"\n";
  	int m = min(b,c);
  	c-=m;
  	b-=m;
  	ans += min(a,c);
  	//cout<<ans<<"\n";
  	if(c>a) ans++;
  	//cout<<ans<<"\n";
  	ans += b;
  	//cout<<b<<" "<<ans<<"\n";
  	cout<<ans;
}