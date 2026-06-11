#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000000;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

short int n,cnt[12],dp[12][1<<23],x,z[1<<23];
int pre;

short int ret,ls;
inline short int hit(int msk){
	if(z[msk]!=-1)return z[msk];
	ret = 24;
	ls = -1;
	rep(i,0,22)if(msk&(1<<i)){
		if(ret>i-ls)ret = i-ls;
		ls = i;
	}
	if(ret>23-ls)ret = 23-ls;
	return z[msk] = ret;
}

short int f(short int pos,int msk){
	if(pos==12)return hit(msk);
	if(dp[pos][msk]!=-1)return dp[pos][msk];
	if(cnt[pos]!=1)return dp[pos][msk] = f(pos+1,msk);
	return dp[pos][msk] = max(f(pos+1,msk|(1<<pos)),f(pos+1,msk|(1<<(22-pos))));
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x;
    	if(x==0)return cout<<"0\n",0;
    	--x;
    	++cnt[x];
    	if(cnt[x]==2)pre|=(1<<x)|(1<<(22-x));
    	else if(cnt[x]==3)return cout<<"0\n",0;
	}
	memset(dp,-1,sizeof dp);
	memset(z,-1,sizeof z);
	cout<<f(0,pre)<<endl;
	return 0;
}