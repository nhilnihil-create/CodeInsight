#include <bits/stdc++.h>
typedef long long int ll;
using namespace std; 
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);
	ll n;cin>>n;
	vector<ll> vect;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			if(i*i!=n){
				vect.push_back(i);
				vect.push_back(n/i);
			}
			else{
				vect.push_back(i);
			}
		}
	}
	ll sum=0;
	for(ll i=0;i<vect.size();i++){
		if(vect[i]>1){
			if(n/(vect[i]-1)==n/vect[i]){
				sum += vect[i]-1;
			}
		}
	}
	cout<<sum<<endl;
}
