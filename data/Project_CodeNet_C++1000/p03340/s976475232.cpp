#include<bits/stdc++.h>
using namespace std;
long long unit = 1;
int visited[105]={0};
bool check(long long curr){
	for(int j=0; j<25; j++){
		if((unit<<j)&curr){
			if(visited[j]) return false;
		}
	}
	for(int j=0; j<25; j++){
		if((unit<<j)&curr) visited[j]++;
	}
	return true;
}
void proccess(long long curr){
	for(int j=0; j<25; j++){
		if((unit<<j)&curr){
			visited[j]--;
		}
	}
}
int main(){
	int n;
	cin>>n;
	vector<long long>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	
	int start = 0;
	int fin = start;
	long long ret = 0;
	while(start<n){
		while(fin<n && check(arr[fin])) fin++;
		ret+=(fin-start);
		proccess(arr[start]);
		start++;
	}
	cout<<ret;
}