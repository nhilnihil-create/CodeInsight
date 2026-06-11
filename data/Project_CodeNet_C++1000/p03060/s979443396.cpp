#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
	int n; cin>>n;
	int a = 0,b = 0;
	int val[n], cost[n];
	for (int i = 0; i < n; i++){
		cin>>val[i];
	}
	for (int i = 0; i < n; i++){
		cin>>cost[i];
	}
	for(int i=0; i<n; i++){
		if(val[i]-cost[i]>0){
			a+=val[i];
			b+=cost[i];
		}
	}
	cout<<a-b<<endl;	
}
