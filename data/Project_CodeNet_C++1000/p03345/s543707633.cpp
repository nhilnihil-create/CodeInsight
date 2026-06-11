#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=998244353;
const int size=3e5+1;
const int inf=1e9;
int main(){
	long A,B,C,K; cin>>A>>B>>C>>K;
	if(K % 2 == 0) cout<<A - B<<endl;
	else cout<<B - A<<endl;
}