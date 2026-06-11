#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l,t,a,b,c,d;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		if(a<b||d<b){
			cout<<"No\n";
			continue;
		}
		a%=b;
		i=__gcd(b,d);
		if((b-a)%i==0){
			j=(b-a)/i-1;
		}
		else{
			j=(b-a)/i;
		}
		if(a+j*i>c){
			cout<<"No\n";
		}
		else{
			cout<<"Yes\n";
		}
	}
}