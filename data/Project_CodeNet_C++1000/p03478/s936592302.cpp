#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	int n,a,b,ans=0;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		int e=0,c=i;
		while(c>0){	
			e+=c%10;
			c/=10;
		}
		if(e>=a && e<=b){
			ans+=i;
		}
	}
	cout<<ans<<endl;
	return(0);
}