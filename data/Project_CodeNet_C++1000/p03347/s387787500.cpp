#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N; cin>>N;
	long A[N];
	rep(i,0,N) cin>>A[i];
	long ans = 0; long t = 0;
	for(int i = N-1; i >= 0; i--){
		if(A[i] > t){ ans += A[i]; t = A[i]; }
        else if(A[i] < t){ cout<<-1<<endl; return 0; }
        t--;
	}cout<<(A[0] ? -1 : ans)<<endl;
}