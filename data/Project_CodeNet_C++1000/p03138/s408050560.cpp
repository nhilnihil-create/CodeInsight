#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;

//for debugging 
/*
g++ -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -std=c++14 
*/
int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}
// debugging ends here

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int modi = 1e9+7;

void solve(){
	ll n,k;
	cin >> n >> k;
	ll maxbit = 0;
	ll ck= k;
	while(ck>0){
		
		maxbit++;
		ck>>=1;
	}
	ll a[n];
	map<ll,ll> cnt;
	ll sum = 0;
	for(ll i =0;i<n;i++){
		cin >> a[i];
		ll ca = a[i];
		ll bit =0;
		while(ca>0){
			if(ca&1)
				cnt[bit]++;
			bit++;
			ca>>=1;
		}
		sum+=a[i];
		// maxbit = max(maxbit,bit);
	}
	vvl dp(maxbit+1,vl(2,-1));

	function<ll(ll,ll)> digit_dp =[&](ll bit, ll smaller){
		// cout << bit << endl;
		if(bit == -1){
			return sum;
		}

		if(dp[bit][smaller]!=-1){
			return dp[bit][smaller];
		}
		ll &ans = dp[bit][smaller];
		ans = 0;
		ll limit=0;
		if(smaller)
			limit=1;
		if(limit == 1){
			ans = max(ans,max(digit_dp(bit-1,1),(1ll<<(bit))*(-2*cnt[bit]+ n) + digit_dp(bit-1,1)));
		}
		else{
			// ll i = 0;
			if((k>>bit)&1){
				ans = max(ans,digit_dp(bit-1,1));
				ans= max(ans,(1ll<<(bit))*(-2*cnt[bit] +n)+digit_dp(bit-1,0));

			}
			else{
				ans = max(ans,digit_dp(bit-1,0));
			}
		}
		return ans;
	};
	ll ans = digit_dp(maxbit-1,0);
	dbg(dp);
	cout << ans << endl;

}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	// int t;cin >> t;while(t--)
		solve();
}
