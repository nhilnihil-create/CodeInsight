#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p;
ll ans=1;
int main(){
	cin>>n>>p;
	if(n==1){
		cout<<p<<endl;
		return 0;
	}
	for(int i=2;i<=sqrt(p);i++){
		if(p%i==0){
			int cnt=0;
			while(p%i==0){
				cnt++;
				p/=i;
				if(cnt%n==0) ans*=i;
			}
		}
		if(p==1) break;
	}
	cout<<ans<<endl;
	return 0;	
}