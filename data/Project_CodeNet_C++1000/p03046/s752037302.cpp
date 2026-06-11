#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=2e5;
const int inf=1e9;
int main(){
	int M,K; cin>>M>>K;
	if((1<<M) <= K) cout<<-1<<endl;
	else if(M == 1 && K == 0) cout<<0<<" "<<0<<" "<<1<<" "<<1<<endl;
	else if(M == 1 && K == 1) cout<<-1<<endl;
	else{
		for(int i = 0; i < (1<<M); i++){
			if(i == K) continue;
			cout<<i<<" ";
		}cout<<K<<" ";
		for(int i = (1<<M)-1; i >= 0; i--){
			if(i == K) continue;
			cout<<i<<" ";
		}cout<<K<<" "<<endl;
	}
}