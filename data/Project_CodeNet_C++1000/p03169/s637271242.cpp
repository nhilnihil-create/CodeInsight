#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pii pair <int,int>
#define pll pair <ll,ll>
#define testcase() int t; cin>>t; while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define forn1(i,n) for(int i=1;i<=n;i++)
#define vll vector <ll>
#define all(v) v.begin(),v.end()

ll M = 1e9 + 7;
double pi = acos(-1.0);
ll powerm(ll x,ll y){ ll res=1; while(y){ if(y&1) res=(res*x)%M; y=y>>1; x=(x*x)%M;} return res%M; }
ll power(ll x,ll y){ ll res=1; while(y){ if(y&1) res=(res*x); y=y>>1; x=(x*x);} return res; }
ll max3(ll a,ll b,ll c){ return max( max(a,b),c ); }
ll gcd(ll a,ll b){if(b>a)return gcd(b,a); if(b==0)return a; return gcd(b,a%b);}
const int N = 305;
double p[N][N][N];
double e[N][N][N];

int main() {
	
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	cout<<fixed<<setprecision(15);
	int n; cin>>n;
	map <int,int> m;
	forn(i,n){ int p; cin>>p; m[p]++; }
	p[m[1]][m[2]][m[3]] = 1.0;
	for(int c=m[3];c>=0;c--)
	{
	    for(int b=m[2]+m[3];b>=0;b--)
	    {
	        for(int a=m[1]+m[2]+m[3];a>=0;a--)
	        {
	            if(a+b+c>n) continue;
	            if( a==0 && b==0 && c==0 ) continue;
	            double ww = (double)( n - (a+b+c) )/(double)n;
	            double ee = 1.0 + ww/(1.0-ww);
	            e[a][b][c] += ee*p[a][b][c];
	            if(a>0)
	            {
	                double gg = (double)a/(a+b+c);
	                p[a-1][b][c] += p[a][b][c]*gg;
	                e[a-1][b][c] += e[a][b][c]*gg;
	            }
	            if(b>0)
	            {
	                double gg = (double)b/(a+b+c);
	                p[a+1][b-1][c] += p[a][b][c]*gg;
	                e[a+1][b-1][c] += e[a][b][c]*gg;
	            }
	            if(c>0)
	            {
	                double gg = (double)c/(a+b+c);
	                p[a][b+1][c-1] += p[a][b][c]*gg;
	                e[a][b+1][c-1] += e[a][b][c]*gg;
	            }
	        }
	    }
	}
	cout<<e[0][0][0];
	
	return 0;
}
