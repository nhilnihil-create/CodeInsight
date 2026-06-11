#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double d;
const int mod=1e9+7;

int main(){
	int n,k;cin>>n>>k;
	d ans=0.0;
	int p2=1;
	for(int i=n;i>=1;i--){
		while(p2*i<k){
			p2*=2;
		}
		//cout<<n*p2<<endl;
		ans+=((1.0/double(n))*(1.0/double(p2)));
	}
	cout<<setprecision(12)<<fixed<<ans;
}