#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e6;
const int inf=1e9;
int main(){
	int N;cin>>N;
	int A[N];pair<int,int> vp[N];
	rep(i,0,N){
		cin>>A[i];
		vp[i]={abs(A[i]),i};
	}
	int id=max_element(vp,vp+N)->second;
	cout<<2*N-1<<endl;
	rep(i,0,N){
		cout<<id+1<<" "<<i+1<<endl;
	}
	if(A[id]>0){
		rep(i,0,N-1){
			cout<<i+1<<" "<<i+2<<endl;
		}
	}else{
		for(int i=N-1;i>0;i--){
			cout<<i+1<<" "<<i<<endl;
		}
	}
}