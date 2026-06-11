#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rb  pop_back
#define rf  pop_front
#define ins insert
#define f   first
#define s   second
#define um  unordered_map
#define us  unordered_set
#define pq  priority_queue

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef pair< long long int ,long long int > iil;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector< ll > vl;
typedef vector< vl > vvl;
typedef vector<double> vd;
typedef pair<double,double> pd;
typedef queue<int> qi;
typedef queue<double> qd;
typedef queue<ll> qll;
typedef us<int> si;
typedef us<double> sd;
typedef us<ll> sll;
typedef vector<vd> md;


const int MAX = 1e6;
const int N = 200043;
const int MOD = 998244353;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define EE endl
#define PI 3.14159265
#define g(a,b) a>b?a:b
#define l(a,b) a<b?a:b
#define SOT(A) sort(A.begin(),A.end())
#define SOTR(A) sort(A.rbegin(),A.rend())
#define REV(a) reverse(ALL(a))

// LOOP Control Statements
#define forn(i,j,n) for ( auto i=j ; i<n ; i++ )
#define fornd(i,j,n) for ( auto i=j ; i>n ; i-- )
#define FORE(i, b) for(auto &i:b)


#define SQ(i) (i*i)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define IN(a, b) (a.find(b) != a.end())
#define BACK(a) a.back(); a.RB()
#define QBACK(a) a.top(); a.pop()
#define PRINT(a) FORE(i, a) cout << i << " "; cout << endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define tcase(term) int tc;cin>>tc;for(int term=0; cout<<"CASE "<<term+1<<EE,term<tc;term++)





int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	// tcase(terms)
	{
		ll n,x,g=1e10;
		cin>>n>>x;
		vl X(n);
		forn(i,0,n) cin>>X[i];
		X.pb(x);
		SOT(X);
		set<ll> A;
		forn(i,1,n+1){
			A.insert(X[i]-X[i-1]);
			g=min(g,X[i]-X[i-1]);
		}
		for(auto y:A){
			// cout<<y<<" "<<g<<endl;
			g=__gcd(g,y);
		}
		cout<<g<<endl;

	}
}
