#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int K; cin>>K;
	long A[K];
	rep(i,0,K) cin>>A[i];
	long a = 2,b = 2 + A[K-1] - 1;
	if(A[K-1] > 2){ cout<<-1<<endl; return 0; }
	for(int i = K - 1; i > 0; i--){
		if(b / A[i-1] * A[i-1] < a){ cout<<-1<<endl; return 0; }
		a = (a + A[i-1] - 1) / A[i-1] * A[i-1];
		b = b / A[i-1] * A[i-1] + A[i-1] - 1;
	}cout<<a<<" "<<b<<endl;
}