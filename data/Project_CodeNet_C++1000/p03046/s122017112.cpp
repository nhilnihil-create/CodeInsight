#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main(){
	int m,K;cin>>m>>K;
	if(m==0){
		if(K==0)puts("0 0");
		else puts("-1");
		return 0;
	}
	if(m==1){
		if(K==0)puts("0 0 1 1 ");
		else puts("-1");
		return 0;
	}
	if(K>=(1<<m)){
		puts("-1");return 0;
	}
	rep(i,1<<m){
		if(i!=K)cout<<i<<' ';
	}
	cout<<K<<' ';
	for(int i=(1<<m)-1;i>=0;i--){
		if(i!=K)cout<<i<<' ';
	}
	cout<<K<<endl;
}