#include<bits/stdc++.h>
using namespace std;

#define fastio 			ios::sync_with_stdio(0);	cin.tie(0); cout.tie(0);  cout<<fixed;  cout<<setprecision(12);
#define randomINT 		mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define	newl 			cout<<"\n"
#define DISP(as)		for(auto it : as) cout<<it<<" ";newl;
#define all(x)         	(x).begin(),(x).end()
#define mset(x,val)    	memset(x,val,sizeof(x))
#define newl           	cout<<"\n"
#define pb             	push_back
#define mp             	make_pair
#define f 				first
#define s 				second
#define dline          cerr<<"///REACHED///\n";
#define deb1(x)        cerr<<#x<<" = "<<x<<'\n';
#define deb2(x,y)      cerr<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define deb3(x,y,z)    cerr<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';

typedef long long 				ll;
typedef long double 			ld;
typedef vector<ll> 				vll;
typedef pair<ll , ll> 			pll;
typedef pair<ld, ld> 			pld;
typedef unordered_map<ll, ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5 + 7;
const ll 	MAX7 	= 	1e+7 + 7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e+9 + 7;

int dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};

// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, m, x, y, q, k;
string s, t;

ll p[20];
vll choice[20];


// <------------- Implement Functions Here ----------> //

ll chk(vll select) {
	for(ll i=1;i<=m;i++) {
		ll cnt = 0;
		for(auto it : choice[i]) {
			cnt += select[it];
		}
		if(cnt%2 != p[i]) return 0;
	}
	return 1;
}

ll recur(vll select, ll i = 1) {
	if(i > n) {
		return chk(select);
	}

	ll sum = recur(select,i+1);
	select[i] = 1;
	sum += recur(select,i+1);

	return sum;
}

// <------------- Start of main() -------------------> //

void MAIN() {
	cin>>n>>m;
	for(ll i=1;i<=m;i++) {
		cin>>x;
		while(x--) {
			cin>>k;
			choice[i].pb(k);
		}
	}
	for(ll i=1;i<=m;i++) cin>>p[i];

	vll select(n+1,0);

	cout<<recur(select);
}

int main() {
	fastio; randomINT;
	//cin >> T;
	while (T--) {
		MAIN();
	}
	return 0;
}
