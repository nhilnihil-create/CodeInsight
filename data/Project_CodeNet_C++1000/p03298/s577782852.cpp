#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N;
string S;
int main(){
    cin>>N>>S;
	ll ans=0;
	for(ll state=0;state<(1<<N);state++){
		string a,b;
		for(ll bit=0;bit<N;bit++){
			if(state & (1<<bit)){
				a+=S[bit];
			}else{
				b+=S[bit];
			}
		}
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		// cout<<"a:"<<a<<endl;
		// cout<<"b:"<<b<<endl;
		ll dp[20][20]={};
		dp[0][0]=1;
		for(ll i=0;i<N;i++){
			char c=S[i+N];
			for(ll j=0;j<=min(i,(ll)a.length());j++){
				if(c==a[j]){
					dp[i+1][j+1]+=dp[i][j];
				}
				if(c==b[i-j]){
					dp[i+1][j]+=dp[i][j];
				}
			}
		}
		ans+=dp[N][a.length()];
	}
	cout<<ans;
    return 0;
}