#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <string>
#include <bitset>
#include <fstream>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<pii> vii;

const ll pr= 1000000007ll;
#define pb push_back
#define mp make_pair
#define err(x) cout<<#x<<"= "<<x<<endl;
#define rep(i,n) for(int i =0; i< n; i++)
#define ff first
#define ss second
#define cil(a,b) ( ((a)%(b) == 0)?((a)/(b)):((a)/(b)+1) )
#define SIZE 100010
#define eps 1e-13

ll exp(ll b, ll e){
	ll ans =1;
	while(e){
		if(e&1)ans = (ans*b)%pr;
		e >>=1;
		b = (b*b)%pr;
	}
	return ans;
}
ll inv(ll a){
	return exp(a,pr-2);
}

ll fact[SIZE],invfact[SIZE],prec[SIZE],A[SIZE],n,ans;

void init(){
	fact[0] = 1;invfact[0] = 1;
	for(int i =1; i<SIZE-1; i++){
		fact[i] = (fact[i-1]*i)%pr;
	//	invfact[i] = inv(fact[i]);
	}
	prec[0] = inv(2);//invfact[2];
	for(int i = 1; i<SIZE-5; i++){
		prec[i] = inv(i+2);//(invfact[i+2]*fact[i])%pr;
		prec[i] += prec[i-1];
		prec[i] %=pr;
	//	cout<<i<<' '<<prec[i]<<endl;
	}
}


int main(){
//	#ifdef ONLINE_JUDGE
//	freopen("little.in", "r" , stdin);
//	freopen("little.out", "w", stdout);
// cin.tie(false); cout.tie(false);	
//	#endif
	ios::sync_with_stdio(false);
	init();
	cin>>n;
	rep(i,n)cin>>A[i];
	rep(i,n) A[i] = (A[i]*fact[n])%pr;
	ans = 0;

	rep(i,n){
		ans+= A[i];
		if(n-i-2>=0)
			ans += (A[i]*prec[n-i-2])%pr;
		ans%=pr;
		if(i-1>=0)
			ans += (A[i]*prec[i-1])%pr;
		ans%=pr;
	//	cout<<ans<<endl;
	}
	cout<<ans<<endl;


	

	return 0;
};
