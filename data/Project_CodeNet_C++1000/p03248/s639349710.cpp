#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

typedef pair<int,int>pi;
typedef vector<int>vi;

const int MAXN=100005;
const int MOD=1000000007;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define DEC(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define db(x) cerr<<#x<<" = "<<x<<"\n"
#define LOW(v,x) (lower_bound(all(v),(x))-(v).begin())
#define UP(v,x) (upper_bound(all(v),(x))-(v).begin())

string s; int n, A[MAXN];
void fail(){
	cout<<-1;
	exit(0);
}
void edge(int x, int y){
	cout<<x<<" "<<y<<"\n";
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	n = s.length();
	FOR(i,1,n) A[i] = (int) s[i-1] - '0';
	if (!A[1]) fail();
	if (A[n]) fail();
	FOR(i,1,n) if (A[i] != A[n-i]) fail();
	
	int prev = 1;
	int sz = 1;
	FOR(i,2,n){
		if (!A[i]) continue;
		edge(prev, sz+1);
		FOR(j, sz+2, i){
			edge(sz+1, j);
		}
		prev = sz+1;
		sz=i;
	}
	edge(prev, n);
}
