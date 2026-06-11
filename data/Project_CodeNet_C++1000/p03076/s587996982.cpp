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
#define N 300000 // prime modulo value 

typedef long long 				ll;
typedef long double 			ld;
typedef vector<ll> 				vll;
typedef pair<ll , ll> 			pll;
typedef pair<ld, ld> 			pld;
typedef unordered_map<ll, ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	3e+5 + 7;
const ll 	MAX7 	= 	1e+7 + 7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e9 + 7;


// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, x, k, p, m, y;
string s, t;
ld w;
ll a, b;


// <------------- Implement Functions Here ----------> //


// <------------- Implement Functions Here ----------> //

bool comp(ll &a, ll &b) {
	ll x = a%10; if(x == 0) x = 10;
	ll y = b%10; if(y == 0) y = 10;
	
	return x > y;
}

// <------------- Start of main() -------------------> //

void MAIN() {	
	ll a,b,c,d,e;
	vll A(5);
	cin >> a >> b >> c >> d >> e;
	
	A[0] = a;
	A[1] = b;
	A[2] = c;
	A[3] = d;
	A[4] = e;

	sort(all(A),comp);
	//DISP(A);

	a = A[0];
	b = A[1];
	c = A[2];
	d = A[3];
	e = A[4];

	ll t = 0;
	t += a;
	t = (t+9)/10 * 10;
	t += b;
	t = (t+9)/10 * 10;
	t += c;
	t = (t+9)/10 * 10;
	t += d;
	t = (t+9)/10 * 10;
	t += e;
	cout<<t;
}

int main() {
	fastio; randomINT;
	//cin >> T;
	while (T--) {
		MAIN();
	}
	return 0;
}