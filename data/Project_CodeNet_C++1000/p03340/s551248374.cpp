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
ll xorsum[200005];
ll sum[200005];
ll bit[200005][25];
ll in[25][200005];
ll dp[200005];
ll ans;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;

rep(i,N) cin>>A[i];

sum[0]=A[0];
xorsum[0]=A[0];
rep1(i,N){
	sum[i]=sum[i-1]+A[i];
	xorsum[i]=xorsum[i-1]^A[i];
}


stringstream ss;
ss << bitset<21>(A[0]);
string s = ss.str();
rep(j,21){
	if(s[j]=='1'){
		bit[0][20-j]=1;
		in[20-j][1]=0;
	}else{
		in[20-j][0]=0;
	}
}

rep1(i,N){
	stringstream ss1;
	ss1 << bitset<21>(A[i]);
	string s1 = ss1.str();
	rep(j,21){
		if(s1[j]=='1'){
			bit[i][20-j]+=bit[i-1][20-j]+1;
			in[20-j][bit[i][20-j]]=i;
		}else{
			bit[i][20-j]+=bit[i-1][20-j];
		}
		
	}
}

rep(i,N){
	if(sum[i]==xorsum[i]) dp[i]++;
}

rep(i,N){
	ll imax=0;
	rep(j,21){
		if(bit[i][j]-1>=0){
			imax=max(imax,in[j][bit[i][j]-1]);
		}
	}
	dp[i]+=i-imax;
}

rep(i,N){
	ans+=dp[i];
	
}

cout<<ans<<endl;

}
	
