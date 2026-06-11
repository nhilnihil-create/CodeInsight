#include <bits/stdc++.h>
using namespace std;

long long N,K,arr[101];

int main(){
	cin>>N>>K;
	for(int i=0; i<N; i++){
		cin>>arr[i];
	}
	sort(arr,arr+N);
	int i=0;
	while(i<N&&K>=0){
		K-=arr[i];
		i++;
	}
	if(K==0){
		cout<<N<<'\n';
	}else if(K>0){
		cout<<N-1<<'\n';
	}else{
		cout<<i-1<<'\n';
	}
}