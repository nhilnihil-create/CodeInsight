#include<bits/stdc++.h>
using namespace std;

int r,d,x,arr[2011];

int main(){
	cin>>r>>d>>x;
	arr[2000] = x;
	for(int i = 2001;i <= 2010;i++){
		arr[i] = r * arr[i - 1] - d;
		cout<<arr[i]<<endl;
	}
}
