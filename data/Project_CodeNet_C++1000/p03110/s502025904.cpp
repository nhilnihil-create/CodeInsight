#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t; cin>>t;
	pair<double, string> arr[t];
	for(int i=0; i<t; i++){
		pair<double, string> aux;
		cin>>aux.first>>aux.second;
		arr[i]=aux;
	}
	double ans = 0;
	for(auto&x : arr){
		if(x.second == "BTC"){
			ans+=(x.first*380000);
		}
		else ans+=x.first;
	}
	cout<<ans<<endl;
}
