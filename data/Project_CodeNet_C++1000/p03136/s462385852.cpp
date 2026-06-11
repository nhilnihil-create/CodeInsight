//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	int n;
	cin>>n;
	int a[n];
	for(int i =0;i<n;i++){
		cin>>a[i];
	}	

	sort(a,a+n);
	ll sum = 0;
	for(int i=0;i<n-1;i++){
		sum += (ll)a[i];
	}

	//cout<<sum<<endl;
	if(sum > a[n-1]){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}


	

	return 0;
}