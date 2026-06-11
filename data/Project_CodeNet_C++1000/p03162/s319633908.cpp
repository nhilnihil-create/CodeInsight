#include "bits/stdc++.h"
using namespace std;
#define all(x) x.begin(),x.end()
#define pb push_back
#define ff first
#define ss second
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ar array
#define int long long
#define F(i,a,b) for(i=a;i<b;++i)
#define RF(i,b,a) for(i=b;i>=a;--i)
#define NL cout<<"\n";

typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
bool comp(ll a,ll b)
{
	return a<b;
}
ll fpow(ll a, ll b) {

	ll res=1;
	while(b) {
		if(b&1)
			res=(res*a);
		a=(a*a);
		b>>=1;
	}
	return res;
}

ll minm(ll a,ll b){
	if(a<b) return a;
	return b;
}

ll maxm(ll a,ll b){
	if(a>b){ return a;}
	else return b;
}

int PHI(int k){
	// This is Euler's Totient Function.
	//This function returns no. of coprime numbers to N in range [1,2,....,N]

	  int ans=k;
	  for(int i=2;i*i<=k;++i){
	  	if(k%i==0){
	  		ans-=ans/i;
	  		while(k%i==0){
	  			k/=i;
	  		}
	  	}
	  }
     if(k>1) ans-=ans/k;
     return ans;


}

const int N=1e5+5;
int dp[N][3];
int a[N],b[N],c[N];
int n;
/*
a->0
b->1
c->2
*/


int rec(int p,int i){

    if(i>=n) return 0;
    if(dp[i][p]!=-1) return dp[i][p];

    if(p==0){
        dp[i][p]=max({dp[i][p], b[i]+rec(1,i+1), c[i]+rec(2,i+1)});

    }

    else if(p==1){
        dp[i][p]=max({dp[i][p],a[i]+rec(0,i+1),c[i]+rec(2,i+1)});

    }
    else
    dp[i][p]=max({dp[i][p] , a[i]+rec(0,i+1) , b[i]+rec(1,i+1) });

    return dp[i][p];



}


void solve(){
  int i;
  cin>>n;
  F(i,0,n){
      cin>>a[i]>>b[i]>>c[i];
      dp[i][0]=dp[i][1]=dp[i][2]=-1;
  }

  int ans=max({ a[0]+ rec(0,1),b[0]+rec(1,1),c[0]+rec(2,1) });
  cout<<ans<<"\n";

}


signed main(void)
{

	fast;

   //#ifndef ONLINE_JUDGE
	//  freopen("input.txt","r",stdin);
	//  freopen("output.txt","w",stdout);
   // #endif

	int test_cases=1;
	//cin>>test_cases;

   while(test_cases--){
   	solve();
   }

}

