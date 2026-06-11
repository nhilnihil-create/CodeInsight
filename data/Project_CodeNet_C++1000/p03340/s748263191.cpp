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
	long A[N+1],B[N+1];
	A[0]=0; B[0]=0;
	long v;
	rep(i,0,N){
		cin>>v;
		A[i+1]=A[i]^v;
		B[i+1]=B[i]+v;
	}
	long cnt=0;
	rep(i,0,N){
		int a=i,b=N+1;
		while(b-a>1){
			if((A[i]^A[(a+b)/2]) == B[(a+b)/2]-B[i]) a=(a+b)/2;
			else b=(a+b)/2;
		}cnt+=a-i;
	}
	cout<<cnt<<endl;
}