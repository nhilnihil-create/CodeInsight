// _______  _____  _______  _____  _______ _______ _____ _______ _____ _    _ _______ 
// |       |     | |  |  | |_____] |______    |      |      |      |    \  /  |______ 
// |_____  |_____| |  |  | |       |______    |    __|__    |    __|__   \/   |______ 
//
//  _____   ______  _____   ______  ______ _______ _______ _______ _____ __   _  ______   /
// |_____] |_____/ |     | |  ____ |_____/ |_____| |  |  | |  |  |   |   | \  | |  ____  / 
// |       |    \_ |_____| |_____| |    \_ |     | |  |  | |  |  | __|__ |  \_| |_____| .  
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define FOR(I,A,B) for(int I = int(A); I < int(B); ++I)
#define FORR(I,A,B) for(int I = int((B)-1); I >= int(A); --I)
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //ai>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //ai>v  x is sorted
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu z
const ll INF=1e18+7;
const ll MOD=1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll N , A , B;
	cin >> N >> A >> B;
	if((A*B<N)||(A+B>N+1)){
		cout << -1 << endl;
		return 0;
	}

	vector<ll> ans;
	FORR(i,1,B+1){
		ans.push_back(i);
	}
	if(A==1){
		FOR(i,0,N){
			if(i!=0)cout << " ";
			cout << ans[i];
		}
		cout << endl;
		return 0;
	}


	ll x = (N-B)/(A-1);
	ll p = (N-B)%(A-1);

	ll nn = B+1;
	FOR(t,0,A-1){
		ll add = x;
		if(p){
			add++;
			p--;
		}
		FORR(i,nn,nn+add){
			ans.push_back(i);
		}
		nn += add;
	}
	FOR(i,0,N){
		if(i!=0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}