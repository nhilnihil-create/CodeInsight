#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int >A(n),B(n);
	vector<int >C;
	for(int i=0;i<n;i++)cin>>A[i];
	for(int i=0;i<n;i++){cin>>B[i];
		if(A[i]>B[i])C.push_back(A[i]-B[i]);
	}

	long long needed = 0;
	int count=0;
	for(int i=0;i<n;i++){
		if(B[i]>A[i])count++;
		needed = needed + max(0,B[i]-A[i]);
	}
	sort(C.rbegin(),C.rend());
	int start=0;
	//cout<<count<<' '<<needed<<'\n';
	//cout<<C[0]<<'\n';
	while(needed!=0 && start!=C.size()){
		if(C[start]<=needed){
			needed -= C[start];
			start++;
		}
		else{
		    needed=0;
		    start++;break;
		}
	}
	if(needed!=0)cout<<-1<<'\n';
	else cout<<start+count<<'\n';
}