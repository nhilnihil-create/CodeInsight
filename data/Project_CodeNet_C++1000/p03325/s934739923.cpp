#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	int arr[n],ans=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]%2==0){
			int val=arr[i],idx=0;
			while(val%2==0){
				idx++;
				val=val/2;
			}
			ans+=idx;
		}
	}
	cout<<ans<<endl;
}


