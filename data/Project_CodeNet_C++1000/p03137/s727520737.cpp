//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	int n,k;
	cin>>n>>k;
	int a[k];

	for(int i=0;i<k;i++){
		cin>>a[i];
	}	

	sort(a,a+k);
	std::vector<int> v;
	for(int i=1;i<k;i++){
		v.push_back(a[i]-a[i-1]);
	}
	sort(v.begin(),v.end());
	ll sum = 0;
	for(int i=(v.size() - n);i>=0;i--){
		//cout<<v[i]<<" ";
		sum += (ll)v[i];
	}//cout<<endl;
	cout<<sum<<endl;
	return 0;
}