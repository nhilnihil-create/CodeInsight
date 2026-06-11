#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

vector<int> places[210000];
ll dp[210000];
void add(ll &a,ll b){a+=b; if(a>=MOD) a-=MOD;}

int main(){
	int n;
	cin>>n;
	vector<int> c(n);
	rep(i,n) cin>>c[i];

	for(int i=0;i<210000;i++) places[i].clear();
	rep(i,n) places[c[i]].push_back(i);

	dp[0]=1;
	for(int i=1;i<=n;i++){
		add(dp[i],dp[i-1]);

		int color=c[i-1];
		int it=lower_bound(places[color].begin(),places[color].end(),i-1)-places[color].begin();
		if(it>0){
			int j=places[color][it-1];
			if((i-1)-j>1) add(dp[i],dp[j+1]);
		}
	} 
	cout<<dp[n]<<endl;
}