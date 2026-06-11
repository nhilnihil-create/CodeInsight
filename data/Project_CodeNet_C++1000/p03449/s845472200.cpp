#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=998244353;
const int siz=1e5;
const long inf=1e9;
int main(){
	int N; cin>>N;
	int A[N+1],B[N+1]; A[0] = B[N] = 0;
	rep(i,0,N) cin>>A[i+1];
	rep(i,0,N) cin>>B[i];
	rep(i,0,N) A[i+1] += A[i];
	for(int i = N; i > 0; i--) B[i-1] += B[i];
	int ans = 0;
	rep(i,0,N) ans = max(ans, A[i+1] + B[i]);
	cout<<ans<<endl;
}