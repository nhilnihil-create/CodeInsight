#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxn = 300+10;
ld memo[maxn][maxn][maxn];
int seen[maxn][maxn][maxn];
int cnt[5],N;

ld dp(int a,int b,int c){
	if(!a && !b && !c)return 0;
	if(seen[a][b][c])return memo[a][b][c];
	seen[a][b][c] = 1;
	ld expectedMalos = ld(N)/ld(a+b+c);
	ld &res = memo[a][b][c];
	res = expectedMalos;
	if(a){
		res += dp(a-1,b,c)*ld(a)/ld(a+b+c);
	}
	if(b){
		res += dp(a+1,b-1,c)*ld(b)/ld(a+b+c);
	}
	if(c){
		res += dp(a,b+1,c-1)*ld(c)/ld(a+b+c);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	forn(i,0,maxn)forn(j,0,maxn)forn(k,0,maxn){
		seen[i][j][k] = 0;
		memo[i][j][k] = 0;
	}
	cin >> N;
	forn(i,0,N){
		int x; cin >> x;
		cnt[x]++;
	}
	ld res = dp(cnt[1],cnt[2],cnt[3]);
	cout << fixed << setprecision(10) << res << '\n';
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/
