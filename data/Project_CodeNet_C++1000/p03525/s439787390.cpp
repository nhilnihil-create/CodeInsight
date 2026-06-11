#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = int(A); I < int(B); ++I)
#define FORR(I,A,B) for(ll I = int((B)-1); I >= int(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll N,k,ans=0;
	cin >> N;
	map<ll,ll> D;
	D[0]++;
	vector<ll> time;
	bool zero = false;
	FOR(i,0,N){
		cin >> k;
		D[k]++;
		if(D[k]==2){
			time.push_back(k);
			time.push_back((24-k)%24);
		}else if(D[k]>2){
			zero = true;
		}
	}
	if(zero){
		cout << 0 << endl;
		return 0;
	}

	vector<ll> kouho;
	FOR(i,0,13){
		if(D[i]==1)kouho.push_back(i);
	}
	ll si = kouho.size();
	FOR(i,0,(1LL<<si)){
		ll ansp = 10000;
		vector<ll> timep=time;
		FOR(j,0,si){
			if(i&(1LL<<j))timep.push_back(kouho[j]);
			else timep.push_back((24-kouho[j])%24);
		}
		timep.push_back(24);
		FOR(j,0,timep.size()){
			FOR(l,0,timep.size()){
				if(j==l)continue;
				ansp = min(ansp,abs(timep[j]-timep[l]));
			}
		}
		ans = max(ans,ansp);
	}
	cout << ans << endl;
}