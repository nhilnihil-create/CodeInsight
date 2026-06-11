#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
	fast_io;
	int k;
	int *arr=new int[5];
	cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4]>>k;
	bool r=true;
	for(int i=0;i<5&&r==true;i++){
		for(int j=i+1;j<5&&r==true;j++){
			if(arr[j]-arr[i]>k)r=false;
		}
	}
	if(r) cout<<"Yay!";
	else cout<<":(";
	return 0;
}
