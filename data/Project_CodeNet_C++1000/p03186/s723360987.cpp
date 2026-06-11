#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c; cin>>a>>b>>c;

	if(a>=c)
		cout<<c+b;
	else{
		int ans = (a+1);
		c = c - ans;

		if(c > b){
			ans += 2*b;
		}else if(b>=c){
			ans+=b+c;
		}cout<<ans<<endl;
	}
	return 0;
}