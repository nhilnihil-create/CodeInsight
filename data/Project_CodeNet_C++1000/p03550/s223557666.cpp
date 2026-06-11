#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9+7;

int main(){

	int n,z,w;
	cin>>n>>z>>w;

	int arr[n];

	for(int i=0;i<n;i++) cin>>arr[i];

	int x = abs(arr[n-1]-w);
	int y = x;
	if(1<n){
		y = abs(arr[n-1]-arr[n-2]);
	}
	
	if(x<y) cout<<y;
	else cout<<x;
}
