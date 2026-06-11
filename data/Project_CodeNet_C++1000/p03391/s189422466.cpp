#include <iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
	int n;cin>>n;
	int minh=-1;
	ll sum=0;
	vector<ll> a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		if(a[i]>b[i]){
			if(~minh==0)minh=b[i];
			if(minh>b[i])minh=b[i];
		}
		sum+=a[i];
	}
	if(~minh){
		cout<<sum-minh<<endl;
	}else{
		cout<<0<<endl;
	}


	return 0;
}
