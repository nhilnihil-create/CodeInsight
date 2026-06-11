#include<bits/stdc++.h>
using namespace std;
int lcd(int a,int b){
	if(a<b) swap(a,b);
	while(b){
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}
int main(){
	int n;
	cin>>n;
	int arr[100005];
	for(int i=1; i<=n; i++) cin>>arr[i];
	int left[100005];
	left[1] = arr[1];
	for(int i=2; i<=n; i++){
		left[i] = lcd(left[i-1],arr[i]);
	}
	int right[100005];
	right[n] = arr[n];
	for(int i=n-1; i>=1; i--){
		right[i] = lcd(right[i+1],arr[i]);
	}
	int ret = max(right[2],left[n-1]);
	for(int i=2; i<n; i++){
		ret = max(ret,lcd(left[i-1],right[i+1]));
	}
	cout<<ret;
}