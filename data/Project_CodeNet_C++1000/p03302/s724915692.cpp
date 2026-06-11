#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define Nmax 200010
#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define RFOR(i,a,b) for(long long i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<P> Graph;

int main() {
	int a,b;cin >> a >> b;
	char s;
	if(a+b==15) s='+';
	else if(a*b==15) s='*';
	else s='x';
	cout << s << endl;
	
	return 0;
}