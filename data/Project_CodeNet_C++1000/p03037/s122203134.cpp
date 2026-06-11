//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	int n,m;
	cin>>n>>m;
	int x,y;
	int L = 0,R = N;
	while(m--){
		cin>>x>>y;
		L = max(L,x);
		R = min(R,y);
	}	

	cout<<max(0,(R - L + 1))<<endl;

	

	return 0;
}