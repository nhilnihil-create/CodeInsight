/*input
10 15
SNCZWRCEWB
B R
R R
E R
W R
Z L
S R
Q L
W L
B R
C L
A L
N L
E R
Z L
S L
*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}

//}}}
const ll maxn=300005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		
		b>>=1;
	}
	return res;
}
int n,q;
string s;

string t[maxn],d[maxn];

int main(){
	IOS;
	cin>>n>>q>>s;
	s="$"+s+"$";
	for(int i=0;i<q;i++){
		cin>>t[i]>>d[i];
	}
	int l=1,r=SZ(s)-2;

	for(int i=q-1;i>=0;i--){
		if(d[i][0]=='L'){
			if(s[l]==t[i][0]){
				l++;
			}
			if(s[r+1]==t[i][0]){
				r++;
			}
		}
		else{
			if(s[r]==t[i][0]){
				r--;
			}
			if(s[l-1]==t[i][0]){
				l--;
			}
		}
		// cout<<l<<' '<<r<<"\n";
	}
	cout<<r-l+1<<'\n';
	return 0;
}
