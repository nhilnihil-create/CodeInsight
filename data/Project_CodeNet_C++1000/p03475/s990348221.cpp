#include<bits/stdc++.h>
using namespace std;
int n;
int dist[505];
int start[505];
int cycle[505];
long long solve(int station){
	long long curr = 0;
	for(int i=station; i<n; i++){
		if(curr<=start[i]){
			curr = start[i];
		}
		else{
			long long left = curr-start[i];
			left%=cycle[i];
			if(left) curr+=cycle[i]-left;
			
		}
		curr+=dist[i];
	}
	return curr;
}
int main(){
	cin>>n;
	for(int i=1; i<n; i++){
		cin>>dist[i]>>start[i]>>cycle[i];
	}
	long long curr = 0;
	for(int i=1; i<n; i++) cout<<solve(i)<<'\n';
	cout<<0;
}