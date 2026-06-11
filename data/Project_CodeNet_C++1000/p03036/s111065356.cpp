//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	ll r,d,x;	
	cin>>r>>d>>x;
	for(int i=0;i<10;i++){
		x = (r*x - d);
		cout<<x<<endl;
	}

	

	return 0;
}