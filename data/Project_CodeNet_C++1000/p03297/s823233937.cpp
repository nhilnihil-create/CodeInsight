#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=998244353;
const int size=3e5+1;
const int inf=1e9;
int main(){
	int T; cin>>T;
	long A,B,C,D;
	rep(i,0,T){
		cin>>A>>B>>C>>D;
		long g = __gcd(B, D);
        long r = (A - C) % D;
		long x = (D - r) / g + 1;
		long y = (g * x + r) - D; //cout<<y<<" ";
        if(B > D || A < B) cout<<"No"<<endl;
		else if(C + y >= B) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}