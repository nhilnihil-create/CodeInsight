#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin>>n;
	long long arr[5];
	for(int i=0; i<5; i++) cin>>arr[i];
	long long bottle_neck = *min_element(arr,arr+5);
	for(int i=0; i<5; i++){
		if(bottle_neck == arr[i]){
			long long ret = 4+n/arr[i];
			if(n%arr[i]) ret++;
			cout<<ret;
			return 0;
		}
	}
}