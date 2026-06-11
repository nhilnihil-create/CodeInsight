#include <bits/stdc++.h>
//#include <math.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;

//-----------------------------------------------------------------------------

string s;
int a,b,c;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>s;
	REP(i,s.size()) (s[i]=='a'?a:s[i]=='b'?b:c)+=1;

	if(abs(a-b)>=2||abs(b-c)>=2||abs(a-c)>=2) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;

	return 0;
}
