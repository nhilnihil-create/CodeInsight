#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define vll vector<ll>
#define G vector<vll >
#define gg vector<int>
#define F first
#define S second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
#define rll read_ll();
#define gc getchar
#define pc putchar
typedef long long ll;
template<class T> inline T lcm(T a,T b){
        return a/gcd(a,b)*b;
}
template<typename T>
void debug(T first) {
    cout << first << "\n";
}
template<typename T, typename... Args>
void debug(T first, Args... args) {
    cout << first << " ";
    debug(args...);
}


ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}

int main()
{
	ll n; 
	scanf("%lld", &n);
	string s; cin>>s;
	ll q; cin>>q;
	vector<pll>pos;
	FOR(i,1,q) {
		ll val; cin>>val;
		pos.emplace_back(val,i);
	}
	sort(all(pos));
	vector<pll>ans;
	ll i = 0;
	while(i < q) {
		ll d = 0, dm = 0, dmc = 0, m = 0;
		ll front = 0;
		FOR(k,0,n-1) {
			char c = s[k], oc = '|';
			if(k < pos[i].F) {
				if(c == 'C') dmc += dm;
				else if( c == 'D') d++;
				else if(c == 'M') m++, dm += d;
			} else {
				oc = s[front++];
				if(oc == 'D') dm -= m, d--;
				if(oc == 'M') m--;

				if(c == 'C') dmc += dm;
				else if( c == 'D') d++;
				else if(c == 'M') m++, dm += d;
			}
		}
		ans.emplace_back(pos[i++].S,dmc);
	}
	sort(all(ans));
	for(auto val : ans) cout<<val.S<<endl;
	return 0;
}