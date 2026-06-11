#include<bits/stdc++.h>
using namespace std;
int main(){
		int a,b,t,ans=0;
		cin>>a>>b>>t;
		if(a>t) cout<<0<<"\n";
		else if(a == t) cout<<1<<"\n";
		else{
			while(t+0.5>a){
				t = t-a;
				ans =ans +b;
			}
					cout<<ans<<"\n";
		}

		return 0;
}