#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	int A[N];
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	bool flag=true;
	for(int i=0;i<N-1;i++){
		if(A[i+1]-A[i]>1){
			flag=false;
			break;
		}
	}
	if(A[0]!=0){
		flag=false;
	}
	if(!flag){
		cout<<-1<<endl;
	}else{
		long long sum=0;
		for(int i=0;i<N-1;i++){
			if(A[i]<A[i+1]){
				sum++;
			}else if(A[i]==A[i+1]){
				sum+=A[i+1];
			}else if(A[i]>A[i+1]&&A[i+1]!=0){
				sum+=A[i+1];

			}
		}
		cout<<sum<<endl;

	}

}

	