#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n; cin>>n;
	bitset<4000010> bt;
	bt[0] = 1;
	int sum = 0;
	for(int i=0;i<n;i++){
		int a; cin>>a;
		sum += a;
		bt|=(bt<<a);
	}
	
	for(int i=(sum+1)/2;i<sum+1;i++){
		if(bt[i]){ cout<<i<<endl; return 0; }
	}
	
	
	return 0;
}
