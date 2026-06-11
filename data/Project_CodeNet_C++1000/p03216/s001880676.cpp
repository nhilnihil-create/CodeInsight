#include<bits/stdc++.h>
using namespace std;

typedef long long lint;

int M[1000100],n,S[1000100],m;
lint sumA=0,sumB=0;

int main(){
	cin>>n;
	for(int i=0;i<n;i++) S[i]=3;
	for(int i=0;i<n;i++){
		char ch;
		cin>>ch;
		if(ch=='D') S[i]=2;
		if(ch=='M') S[i]=1;
		if(ch=='C') S[i]=0;
	}
	for(int i=0;i<n;i++){
		if(S[i]==1) M[i]++;
		if(i!=0) M[i]+=M[i-1];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int k;
		lint sumA=0,ans=0;
		cin>>k;
		queue <int> Q;
		for(int j=0;j<n;j++){
			if(S[j]==0){
				while(Q.front()+k<j+1&&Q.size()>0){
					sumA-=M[Q.front()];
					Q.pop();
				}
				ans+=Q.size()*M[j]-sumA;
			}
			if(S[j]==2){
				Q.push(j);
				sumA+=M[j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}