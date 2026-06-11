#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
vector<pi>ret;
int main(){
	bool pos = false;
	bool neg = false;
	int n;
	cin>>n;
	long long arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(arr[i]>0) pos = true;
		else if(arr[i]<0) neg = true;
	}	
	if(pos && neg){
		long long mn = *min_element(arr,arr+n);
		long long mx = *max_element(arr,arr+n);
		if(abs(mx)>=abs(mn)){ //양수가 더 힘이 세다면 
			int index;
			for(int i=0; i<n; i++){
				if(arr[i]==mx){
					index = i;
					break;
				}
			}
			cout<<2*n-1<<'\n';
			for(int i=1; i<=n; i++) cout<<index+1<<" "<<i<<'\n';
			for(int i=1; i<n; i++) cout<<i<<" "<<i+1<<'\n';
		}
		else{
			int index;
			for(int i=0; i<n; i++){
				if(arr[i]==mn){
					index = i;
					break;
				}
			}
			cout<<2*n-1<<'\n';
			for(int i=1; i<=n; i++) cout<<index+1<<" "<<i<<'\n';
			for(int i=n; i>1; i--) cout<<i<<" "<<i-1<<'\n';
		}
	}
	if(pos && !neg){
		cout<<n-1<<'\n';
		for(int i=0; i<n-1; i++) cout<<i+1<<" "<<i+2<<'\n';
	}
	if(!pos && neg){
		cout<<n-1<<'\n';
		for(int i=n-1; i>0; i--) cout<<i+1<<" "<<i<<'\n';
	}
	if(!pos && !neg){
		cout<<0;
	}
}