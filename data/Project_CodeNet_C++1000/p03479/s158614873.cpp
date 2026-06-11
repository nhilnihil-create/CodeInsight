#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll x,y,ans=0;
  	cin>>x>>y;
  	while(x <=y){
    	ans++;
      	x = x*2;
    }
  	cout<<ans<<"\n";
	return 0;
}