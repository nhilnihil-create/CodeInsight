#include<bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int>
#define REP(i,a) for(int (i)=0; (i)<(a); (i)++)
#define RREP(i,a) for(int (i)=a-1; (i)>=(0); (i)--)
#define REP2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define m0(x) memset(x,0,sizeof(x))
typedef long long ll;
using namespace std;



int main(){
	ll N; cin>>N;
	string s; cin>>s;
	vector<ll> siro(N+1,0);
	vector<ll> kuro(N+1,0);
	REP(i,N) kuro[i+1] = kuro[i] + (s[i] == '#');
	for(int i = N-1; i>=0; --i) siro[i] = siro[i+1] + (s[i] == '.');
	ll ans = N;
	REP(i,N+1){
		ans = min(ans, siro[i] + kuro[i]);
	}
	cout << ans;
  	return 0;
}
