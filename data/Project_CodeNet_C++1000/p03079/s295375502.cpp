#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef vector<int> Vi;
typedef vector<lli> Vl;
typedef pair<int, int> Pii;
typedef pair<lli, lli> Pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<": ";REP(i,v.size())cout<<" "<<v[i];cout<<endl

#define ALL(a) (a).begin(), (a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))


//===


int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	cout << (A == B && A == C ? "Yes" : "No") << endl;
}