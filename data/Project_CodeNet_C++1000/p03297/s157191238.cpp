#include <bits/stdc++.h>
using namespace std;
int t;
long long a,b,c,d;
void no(){
	cout<<"No\n";
}
void yes(){
	cout<<"Yes\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		if(a<b){
			no();
			continue;
		}
		if(d<b){
			no();
			continue;
		}
		if(c+1>=b){
			yes();
			continue;
		}
		long long p=a%__gcd(b,d);
		p-=__gcd(b,d);
		if(p>=c+1-b){
			no();
		}
		else yes();
	}
}
