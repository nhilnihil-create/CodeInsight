#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	long long Z,W,p,q;
	cin>>N>>Z>>W;
	cin>>q;
	for(int i=0;i<N-1;i++){
		p=q;
		cin>>q;
	}
	if(N>1){
		cout<<max(abs(p-q),abs(q-W))<<endl;
	}else{
		cout<<abs(q-W)<<endl;
	}
	return 0;
}