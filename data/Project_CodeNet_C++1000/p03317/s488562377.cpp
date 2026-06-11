#include<bits/stdc++.h>
using namespace std;
#define int 	long long int

int32_t main(){
	
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int idx=0,temp=n;

	while(temp>0){
		if(temp==k){
			idx++;
			break;
		}
		else
		{
			temp=temp-(k-1);
			idx++;
		}
	}

	cout<<idx<<endl;

}


