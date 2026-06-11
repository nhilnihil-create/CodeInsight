#include <bits/stdc++.h> 

using namespace std;

#define fcout(d) cout << fixed << setprecision(d)
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define repU(i,s,t) for(int i = (s); i <= (t); ++i)
#define repD(i,t,s) for(int i = (t); i >= (s); --i)
#define all(v)  begin(v),end(v)
#define clr(v) fill(all(v),0)
#define l_bnd lower_bound
#define u_bnd upper_bound
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define rem(n,d) (((n % d) + d) % d)
#define q_ceil(n,d) ((n - 1)/(d) + 1)
#define parity(a,b) (((a)^(b)) & 1 ^ 1)

typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const pair<int,int> DIR[] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int INF_32 = -1 + (1 << 30);
const ll INF_64 = -1 + (1LL << 62);
const int MOD = 1e9 + 7;

int n;
vector<int> s = {2,3,4,9};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin>>n; 
	if(n == 3){ cout<<"2 5 63\n"; return 0; }
	n -= 4;
	rep1(i,5000){
		if(!n){
			for(int i : s) cout<<i<<' ';
			cout<<'\n';
			return 0;
		}
		s.pub(6 * i);
		--n;
	}
	if(n & 1){ s.pob(); ++n; }
	rep1(i,4999){
		if(!n){
			for(int i : s) cout<<i<<' ';
			cout<<'\n';
			return 0;
		}
		s.pub(6 * i + 2);
		s.pub(6 * i + 4);
		n -= 2;
	}
	rep1(i,2499){
		if(!n){
			for(int i : s) cout<<i<<' ';
			cout<<'\n';
			return 0;
		}
		s.pub(12 * i + 3);
		s.pub(12 * i + 9);
		n -= 2;
	}
	
	if(!n){
			for(int i : s) cout<<i<<' ';
			cout<<'\n';
			return 0;
		}
}
