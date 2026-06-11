#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=2e5;
const int inf=1e9;
int main(){
	int N,K;cin>>N>>K;
	long a; long acm[N+1]; acm[0] = 0;
	rep(i,0,N){ cin>>a; acm[i+1] = acm[i] + a; }
    vector<long> vec[2];
    rep(j,0,N+1)rep(k,0,j) vec[0].push_back(acm[j] - acm[k]);
	long ans = 0;
	for(int i = 50; i >= 0; i--){
		long t;bool flag;
		int cnt = 0;
		for(long t:vec[0]){
            flag = true;
			if(flag && (t & (1ll<<i))){ cnt++; vec[1].push_back(t); }
		}
        if(cnt >= K){
            ans |= (1ll<<i);
            vec[0].clear();
            for(long x:vec[1]) vec[0].push_back(x);
        }vec[1].clear();
	}cout<<ans<<endl;
}