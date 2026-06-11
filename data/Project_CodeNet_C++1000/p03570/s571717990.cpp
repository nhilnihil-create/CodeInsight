#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; ++i)
#define FOR(i,n,m) for(long long i=n; i<m; ++i)
#define DUMP(n,a) for(long long dump=0; dump<n; ++dump) { cout<<a[dump]; if(dump!=n-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
 
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	map<ll,ll> m;
	vector<ll> c(26,0);
	vector<ll> d((ll)s.size()+1);
	REP(i,(ll)s.size()) {
		ll buf1=1;
		ll buf2=0;
		REP(j,26) {
			if(c[j]%2==1) {
				buf2+=buf1;
			}
			buf1*=2;
		}
		d[i]=buf2;
		m[buf2]=INF;
		c[s[i]-'a']++;
	}
	ll buf1=1;
	ll buf2=0;
	REP(i,26) {
		if(c[i]%2==1) {
			buf2+=buf1;
		}
		buf1*=2;
	}
	d[(ll)s.size()]=buf2;
	m[buf2]=INF;
	m[0]=0;
	REP(i,(ll)s.size()+1) {
		ll ret=INF;
		ret=min(ret,m[d[i]]+1);
		REP(j,26) {
			ll buf=d[i];
			if(d[i]%(1<<(j+1))!=d[i]%(1<<(j))) {
				buf-=(1<<(j));
			} else {
				buf+=(1<<(j));
			}
			if(m.count(buf)!=0) ret=min(ret,m[buf]+1);
		}
		m[d[i]]=min(m[d[i]],ret);
	}
	if(d[(ll)s.size()]==0) cout<<1<<endl;
	else cout<<m[d[(ll)s.size()]]<<endl;
}