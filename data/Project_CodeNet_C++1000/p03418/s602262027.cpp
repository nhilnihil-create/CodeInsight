#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll n,k;
	cin>>n>>k;

	ll res = 0;


	for(int i = k+1;i<=n;i++){
		res+=((n-n%i)/i)*(i-k);
		//cout<<"res:"<<i<<" "<<res<<endl;
		ll r = n%i;
		if(n%i>=k && n%i!=0 && k!=0) res+=(r - (k - 1));
		if(n%i>=k && n%i!=0 && k==0) res+=(r - (k));
	//	cout<<i<<" "<<res<<endl;
	}
	cout<<res;
}


 //i - k  i-1 
