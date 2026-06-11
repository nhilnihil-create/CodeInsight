#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N;
ll A[200005];
ll B[200005];
ll dp[200005];

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;

rep1(i,N+1){
	cin>>A[i];
	B[i]=A[i]-i;
}
sort(B+1,B+1+N);

rep1(i,N+1){
	dp[1]+=abs(B[i]-B[1]);
} 

rep1(i,N){
	dp[i+1]=dp[i]+i*(B[i+1]-B[i])-(N-i)*(B[i+1]-B[i]);
}

ll ans=9223372036854775807;
rep1(i,N+1){
	ans=min(ans,dp[i]);
}

cout<<ans<<endl;

}
	
