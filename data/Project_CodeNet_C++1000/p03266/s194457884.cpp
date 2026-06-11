#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int siz=2e5;
const long inf=1e9;
int main(){
	long N,K; cin>>N>>K;
	if(K % 2 == 0){
		long a = N / K;
		long b = (N + K/2) / K;
		cout<<a * a * a + b * b * b<<endl;
	}else{
		long a = N / K;
		cout<<a * a * a<<endl;
	}
}