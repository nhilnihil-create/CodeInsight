#include<bits/stdc++.h>
using namespace std;
int h,w;
int arr[205][205];
int cost[12][12];
int f(int num){
	if(num==-1) return 0;
	return cost[num][1];
}
int main(){
	cin>>h>>w;
	
	for(int i=0; i<=9; i++){
		for(int j=0; j<=9; j++) cin>>cost[i][j];
	}
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++) cin>>arr[i][j];
	}
	for(int k=0; k<=9; k++){
		for(int i=0; i<=9; i++){
			for(int j=0; j<=9; j++){
				cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
			}
		}
	}
	long long ret = 0;
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			ret+=f(arr[i][j]);
		}
	}
	cout<<ret;
}