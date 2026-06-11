#include<bits/stdc++.h>

#define PI 3.1415926535897932384626
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,a,b) for(i=a;i<b;i++)
#define ll long long
#define pb push_back
#define popb pop_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define ini(a) memset(a,-1,sizeof(a))
#define M (ll)(1e9+7)

#define chk(a) cout << endl << #a << " : " << a << endl
#define chk2(a,b) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl


using namespace std;

typedef pair<int, int>	pi;
typedef pair<int,pi>    pii;
typedef pair<ll, ll>	pl;
typedef pair<ll,pl>     pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pi>		vpi;
typedef vector<pii>     vpii;
typedef vector<pl>		vpl;
typedef vector<pll>     vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;


void add_self_modulo(ll &a,ll b){
	a+=b;
	if(a>=M){
		a-=M;
	}
}

void sub_self_modulo(ll &a,ll b){
	a-=b;
	if(a<0LL){
		a+=M;
	}
}


void solve(){
	
	ll n,k,K,i,j,aj;
	cin>>n>>K;
	//cout<<n<<" "<<K<<endl;
	ll a[n];
	fo(i,n){cin>>a[i];}
	vector<ll> dp(K+1,0);
	dp[0]=1LL;

	//dp[i]=no of ways to distribute i candies among j children
	
	fo(i,n){
		vector<ll> fake(K+2,0LL);
		//for(ll used_candies=K;used_candies>=0LL;used_candies--){
		for(ll used_candies=0;used_candies<=K;used_candies++){
			ll limit=min(a[i],K-used_candies);
			ll L=used_candies+1;
			ll R=used_candies+limit;
			if(L>R)continue;
			add_self_modulo(fake[L],dp[used_candies]);
			sub_self_modulo(fake[R+1],dp[used_candies]);
		}
		ll prefix_sum=0LL;
		for(j=0;j<=K;j++){
			add_self_modulo(prefix_sum,fake[j]);
			add_self_modulo(dp[j],prefix_sum);
		}
	}
	//cout<<"hey\n";
	cout<<dp[K]<<endl;
	//cout<<"hi\n";




}



int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin>>t;
	while(t--){
		solve();
	}
return 0;
}