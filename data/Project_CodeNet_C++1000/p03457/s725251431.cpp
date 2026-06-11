#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int n;cin>>n;

	int t[n],x[n],y[n];

	for(int i=0;i<n;i++)cin>>t[i]>>x[i]>>y[i];

	for(int i=0;i<n;i++){
		int dis,time;
		if( i==0 ){
			dis = x[i]+y[i];
			time = t[i];
		}
		else{
			time = t[i]-t[i-1];
			dis = abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
		}


		if(dis>time){
			cout<<"No\n";
			return 0;
		}
		else{
			int rem = time-dis;
			if( rem%2!=0 ){
				cout<<"No\n";
				return 0;
			}
		}
	}
	cout<<"Yes\n";
	return 0;

	/*
	1. Check for output format
	2. CHeck for corner cases
	3. Compile and run given TC first
	*/

}